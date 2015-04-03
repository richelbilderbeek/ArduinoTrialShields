/*

  Led Trial Shield, White Belt
  (C) 2015 Thijs van Beers

*/
//pin 13 is connected to the LED on the Trial Shield

void setup() {
  pinMode(13, OUTPUT);    //the LED is an output
}

void loop() {
  digitalWrite(13, !digitalRead(13));  //write the LED what it is not now (on when it's off, off when it's on)
  delay(1000);                         //wait a second
}
