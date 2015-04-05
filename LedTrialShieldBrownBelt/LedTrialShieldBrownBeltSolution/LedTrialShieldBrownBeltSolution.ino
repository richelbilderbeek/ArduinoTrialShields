/*

  Led Trial Shield, Brown Belt
  (C) 2015 Thijs van Beers

*/

//The RGB LED is connected to these pins on the Trial Shield
const int green = 11;
const int red   = 10;
const int blue  = 9;

void setup(){
  //The RGB LED is an output
  pinMode(green, OUTPUT);
  pinMode(red,   OUTPUT);
  pinMode(blue,  OUTPUT);
}

void loop(){
  //Going from full red to full green by decreasing the red value and increasing the green value
  for(int i=0; i!=256; ++i){
    const int u = map(i,0,255,255,0);
    analogWrite(red, u);
    analogWrite(green, i);
    delay(10);
  }
  //Going from full green to full blue by decreasing the green value and increasing the blue value
  for(int i=0; i!=256; ++i){
    const int u = map(i,0,255,255,0);
    analogWrite(green, u);
    analogWrite(blue, i);
    delay(10);
  }
  //Going from full blue to full red by decreasing the blue value and increasing the red value
  for(int i=0; i!=256; ++i){
    const int u = map(i,0,255,255,0);
    analogWrite(blue, u);
    analogWrite(red, i);
    delay(10);
  }
  
}
