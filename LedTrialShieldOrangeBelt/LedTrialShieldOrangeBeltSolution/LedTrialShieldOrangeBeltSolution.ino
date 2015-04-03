/*

  Led Trial Shield, Orange Belt
  (C) 2015 Thijs van Beers

*/

#include <SevenSeg.h>//You can find this class at https://github.com/richelbilderbeek/ArduinoCourse/tree/master/Code/Classes/SevenSeg

//The display is connected to these pins on the Trial Shield
SevenSeg Display = SevenSeg(2,3,4,5,6,7,8,9);

void setup() {
  //Nothing to set up
}

void loop() {
  //Display numbers 0 to 9 for one second each
  for(int i=0; i!=10; ++i){
    Display.writeDigit(i);
    delay(1000);
    Display.clearDisplay();
  }
}
