#include <SoftwareSerial.h>
int sensorPin = A0;
int sensorValue = 0;
int led = 9;
int buzz = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if(sensorValue < 100)
  {
    Serial.println("Fire detected");
    Serial.println("LED on");
    digitalWrite(led, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
  }
  digitalWrite(led, LOW);
  digitalWrite(buzz, LOW);
  delay(100);
}
