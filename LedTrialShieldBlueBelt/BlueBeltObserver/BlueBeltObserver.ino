void setup() {
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() 
{
  const int sensorValue = analogRead(A0);
  analogWrite(11,map(sensorValue,0,1024,0,255));
  Serial.println(sensorValue);
  delay(100);
}
