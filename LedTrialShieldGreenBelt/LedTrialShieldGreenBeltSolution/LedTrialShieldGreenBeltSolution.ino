/*

  Led Trial Shield, Green Belt
  (C) 2015 Thijs van Beers and Richel Bilderbeek

*/

//The RGB LED is connected to these pins on the Trial Shield
const int green = 11;
const int red   = 12;
const int blue  = 13;

void setup() {
  //The RGB LED is an output
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  //Turn the RGB LED red for a second
  digitalWrite(red, HIGH);
  delay(1000);
  //Turn the RGB LED green for a second
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(1000);
  //Turn the RGB LED orange for a second
  digitalWrite(red, HIGH);
  analogWrite(green, 128);
  delay(1000);
}
