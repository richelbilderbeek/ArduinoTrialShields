/*
This is the Oriental Riff; 
an asian sounding tune made famous by the song "Kung Fu Fighting" by Carl Douglas
I choped it up in to 7 parts (indicated by the numbers) so we can use it for our belt system.
With every belt you hear a little more of the tune until, at the black belt, you hear the entire thing.
The letters indicate what note is played and how many times.
*/

const int speaker = 13;

void setup() {
  pinMode(speaker, OUTPUT);
}

void loop() {
  //DDDD  (D4)
  tone(speaker, 294, 250);
  delay(250);
  noTone(speaker);
  delay(10);
  tone(speaker, 294, 250);
  delay(250);
  noTone(speaker);
  delay(10);
  //1
  tone(speaker, 294, 250);
  delay(250);
  noTone(speaker);
  delay(10);
  tone(speaker, 294, 250);
  delay(250);
  noTone(speaker);
  
  delay(50);
  //2
  
  //CC  (C4)
  tone(speaker, 262, 500);
  delay(500);
  noTone(speaker);
  delay(10);
  //3
  tone(speaker, 262, 500);
  delay(500);
  noTone(speaker);
  
  delay(50);
  //4
  
  //BB  (B3)
  tone(speaker, 247, 500);
  delay(500);
  noTone(speaker);
  delay(10);
  //5
  tone(speaker, 247, 500);
  delay(500);
  noTone(speaker);
  
  delay(50);
  //6
  
  //C  (C4)
  tone(speaker, 262, 500);
  delay(500);
  noTone(speaker);
  //7
  
  delay(5000);  
}
