int character = 0;
int pin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    character = Serial.read();
    if(character == 65)
    {
    Serial.print("I received ");
    Serial.println(character, DEC);
    digitalWrite(pin, HIGH);
    delay(2000);
    }
  }
  else
  {
    digitalWrite(pin, LOW);
  }
}
