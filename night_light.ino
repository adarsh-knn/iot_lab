int pin = A0;
int outputPin = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, INPUT);
  pinMode(outputPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  Serial.println(value);
  delay(500);
  if (value >= 200)
  {
    digitalWrite(outputPin, LOW);
    Serial.println(value);
  }
  else
  {
    digitalWrite(outputPin, HIGH);
    Serial.println(value);
  }
}
