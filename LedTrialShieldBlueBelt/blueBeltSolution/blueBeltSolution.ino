const int ledPin = 9;    

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int fadeValue = 0 ; fadeValue <= 255; ++fadeValue) {
    analogWrite(ledPin, fadeValue);
    delay(10);
  }
  for (int fadeValue = 0 ; fadeValue <= 255; --fadeValue) {
    analogWrite(ledPin, fadeValue);
    delay(10);
  }
}


