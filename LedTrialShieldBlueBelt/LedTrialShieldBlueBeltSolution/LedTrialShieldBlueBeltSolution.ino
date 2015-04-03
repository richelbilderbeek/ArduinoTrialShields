/*

  Led Trial Shield, Blue Belt
  (C) 2015 Thijs van Beers and Richel Bilderbeek

*/

//The LED is connected to pin 9 on the Trial Shield
const int ledPin = 9;    

void setup() 
{
  //The LED is an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //For loop fading the LED on
  for (int fadeValue = 0 ; fadeValue < 256; ++fadeValue) 
  {
    analogWrite(ledPin, fadeValue);
    delay(10);
  }
  //For loop fading the LED off
  for (int fadeValue = 255 ; fadeValue > -1; --fadeValue) 
  {
    analogWrite(ledPin, fadeValue);
    delay(10);
  }
}


