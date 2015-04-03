/*

  Led Trial Shield, Blue Belt
  (C) 2015 Thijs van Beers and Richel Bilderbeek

*/

const int ledPin = 9;    

void setup() 
{
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int fadeValue = 0 ; fadeValue < 256; ++fadeValue) 
  {
    analogWrite(ledPin, fadeValue);
    delay(10);
  }
  for (int fadeValue = 255 ; fadeValue > -1; --fadeValue) 
  {
    analogWrite(ledPin, fadeValue);
    delay(10);
  }
}


