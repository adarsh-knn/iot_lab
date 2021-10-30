int echoPin = 7;
int trigPin = 8;
int duration;
int inches;
int cm;
int output = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondstoinches(duration);
  cm = microsecondstocenti(duration);
  Serial.print("Inches : ");
  Serial.println(inches);
  Serial.print("Centi : ");
  Serial.println(cm);
  if (cm <= 4)
  {
    digitalWrite(output, HIGH);
  }
  else
  {
    digitalWrite(output, LOW);
  }    
  delay(1000);
}

long microsecondstoinches(long duration)
{
  return duration / 74 /2;
}

long microsecondstocenti(long duration)
{
  return duration / 29 /2;
}
