/*

  Led Trial Shield, White Belt
  (C) 2015 Thijs van Beers

*/

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, !digitalRead(13));  
  delay(1000);             
}
