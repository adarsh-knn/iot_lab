const int analogInPin = A0;
const int analogOutPin = 9;

int sensorValue = 0;
int outputValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    sensorValue = analogRead(analogInPin);
    outputValue = map(sensorValue, 0, 1023, 0, 255);
    analogWrite(analogOutPin, outputValue);
    Serial.print("Input value ");
    Serial.println(sensorValue);
    Serial.print("Output value ");
    Serial.println(outputValue);
    Serial.println();
    delay(1000);    
}
