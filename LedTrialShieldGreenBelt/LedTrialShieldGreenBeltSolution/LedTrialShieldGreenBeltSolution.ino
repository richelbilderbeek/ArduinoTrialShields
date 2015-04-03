/*

  Led Trial Shield, Green Belt
  (C) 2015 Thijs van Beers and Richel Bilderbeek

*/

const int green = 11;
const int red   = 12;
const int blue  = 13;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(red, HIGH);
  analogWrite(green, 128);
  delay(1000);
}
