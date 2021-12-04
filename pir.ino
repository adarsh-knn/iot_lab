int LDR = 0; //analog pin to which LDR is connected, here we set it to 0 so it means A0
int LDRValue = 0; //that’s a variable to store LDR values
int light_sensitivity = 500; //This is the approx value of light surrounding your LDR
//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;
//the time when the sensor outputs a low impulse
long unsigned int lowIn;
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int pirPin = 3; //the digital pin connected to the PIR sensor's output
int ledPin = 11;
void setup()
  {
    Serial.begin(9600); //start the serial monitor with 9600 buad
    pinMode(11, OUTPUT);
    pinMode(pirPin, INPUT);
    pinMode(ledPin, OUTPUT);
    digitalWrite(pirPin, LOW);
    Serial.print("calibrating sensor ");//give the sensor some time to calibrate
    for(int i = 0; i<calibrationTime; i++){
        Serial.print(".");
        delay(1000);
     }
     Serial.println(" done");
     Serial.println("SENSOR ACTIVE");
     delay(50);
  }
void loop()
  {
    LDRValue = analogRead(LDR); //reads the ldr’s value through LDR
    // Serial.println(LDRValue); //prints the LDR values to serial monitor
      if(digitalRead(pirPin) == HIGH && LDRValue < light_sensitivity){
        digitalWrite(ledPin, HIGH);
        if(lockLow){
            //makes sure we wait for a transition to LOW before any further output is made:
            lockLow = false;
            Serial.println("---");
            Serial.print("motion detected at ");
            Serial.print(millis()/1000);
            Serial.println(" sec");
            delay(50);
         }
        takeLowTime = true;
      }
      if(digitalRead(pirPin) == LOW || LDRValue >= light_sensitivity){
          digitalWrite(ledPin, LOW); //the led visualizes the sensors output pin state
          if(takeLowTime){
            lowIn = millis(); //save the time of the transition from high to LOW
            takeLowTime = false; //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause,
       //we assume that no more motion is going to happen
      if(!lockLow&&millis() - lowIn> pause){
           //makes sure this block of code is only executed again after
           //a new motion sequence has been detected
        lockLow = true;
        Serial.print("motion ended at "); //output
        Serial.print((millis() - pause)/1000);
        Serial.println(" sec");
        delay(50);
    }
      delay(100);
  }
}
