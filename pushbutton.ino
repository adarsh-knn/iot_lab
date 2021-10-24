int digitalInPin = 2;
int digitalOutPin = 13;
int val = 0;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(digitalInPin, INPUT);
  pinMode(digitalOutPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(digitalInPin);
  if(val == HIGH)
  {
    digitalWrite(digitalOutPin, HIGH);
    count++;
    Serial.println(count);
    delay(500);
  }
  else
  {
    digitalWrite(digitalOutPin, LOW);
  }
}
