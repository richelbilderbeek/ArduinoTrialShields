#include <SevenSeg.h>

SevenSeg Display = SevenSeg(2,3,4,5,6,7,8,9);

const int green = 12;
const int red   = 11;
const int blue  = 10;

int time0;
int time1;
int digit = 0;
int state = 0;
int i = 0;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(red,   OUTPUT);
  pinMode(blue,  OUTPUT);
  
  time0 = millis();
  time1 = millis();
}

void loop() {
  if(millis() - time0 >= 1000){
    Display.writeDigit(digit % 10);
    ++digit;
    time0 = millis();
  }
  
  if(millis() - time1 >= 10){
    ++i;
    int u = map(i,0,255,255,0);
    
    switch(state){
      case 0:
      analogWrite(red,u);
      analogWrite(green,i);
      analogWrite(blue, 0);
      if(i == 255){
        i = 0;
        state = 1;
      }
      break;
      
      case 1:
      analogWrite(green, u);
      analogWrite(blue, i);
      analogWrite(red, 0);
      if(i == 255){
        i = 0;
        state = 2;
      }
      break;
      
      case 2:
      analogWrite(blue, u);
      analogWrite(red, i);
      analogWrite(green, 0);
      if(i == 255){
        i = 0;
        state = 0;
      }
      break;
    }
    
    time1 = millis();
  }
}
