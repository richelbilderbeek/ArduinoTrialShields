#include <SevenSeg.h>

SevenSeg Display = SevenSeg(2,3,4,5,6,7,8,9);

void setup() {
  
}

void loop() {
  for(int i=0; i!=10; ++i){
    Display.writeDigit(i);
    delay(1000);
    Display.clearDisplay();
  }
}
