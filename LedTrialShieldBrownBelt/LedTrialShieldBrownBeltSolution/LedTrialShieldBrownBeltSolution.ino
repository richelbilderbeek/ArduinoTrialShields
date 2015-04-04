const int green = 11;
const int red   = 10;
const int blue  = 9;

void setup(){
  pinMode(green, OUTPUT);
  pinMode(red,   OUTPUT);
  pinMode(blue,  OUTPUT);
}

void loop(){
  for(int i=0; i!=256; ++i){
    const int u = map(i,0,255,255,0);
    analogWrite(red, u);
    analogWrite(green, i);
    delay(10);
  }
  for(int i=0; i!=256; ++i){
    const int u = map(i,0,255,255,0);
    analogWrite(green, u);
    analogWrite(blue, i);
    delay(10);
  }
  for(int i=0; i!=256; ++i){
    const int u = map(i,0,255,255,0);
    analogWrite(blue, u);
    analogWrite(red, i);
    delay(10);
  }
  
}
