/*

  Led Trial Shield, Blue Belt
  (C) 2015 Thijs van Beers

*/

//The pins of the piezo and the LED
const int led = A0;
const int successPin = 12;

int pointA;
int pointB;
int pointC;
int check = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Start Trial");
  //The LED is an input, the piezo an output
  pinMode(led,INPUT);
  pinMode(successPin,OUTPUT);
}

int GetPwm(const int pin_read)
{
  const int dist_micro_sec_int = pulseIn(pin_read,HIGH,1000);
  if (dist_micro_sec_int == 0){
    if(digitalRead(pin_read) == LOW) return 0;
    else if(digitalRead(pin_read) == HIGH) return 255;
  }
  const double dist_micro_sec = static_cast<double>(dist_micro_sec_int);
  const double period_micro_sec = (1.0 / 490.0) * (1000.0 * 1000.0); //microsecond
  const double f = dist_micro_sec / period_micro_sec * 1.151; //compensate for rounding fault
  const double pwm = f * 255.0;
  return static_cast<int>(pwm);
}

void loop() 
{
  //Start when the LED is off
  const int ledValue = GetPwm(led);
  if(ledValue == 0){
    delay(1275);
    Serial.println("Start poin A");
    //Point A should be half way in to the fading on, so it should be 128
    pointA = GetPwm(led);
    if(pointA > 118 && pointA < 138){
      delay(1275);
      Serial.println("Start poin B");
      //Point B should be when te LED is fully on, so it should be 255
      pointB = GetPwm(led);
      if(pointB > 245){
        delay(1275);
        Serial.println("Start poin C");
        //Point C should be half way before the LED is fully off, so it should be 128
        pointC = GetPwm(led);
        if(pointC > 118 && pointC < 138){
          //If it is correct add one to check, otherwise reset check
          Serial.println("All points were correct!");
          ++check;  
        }
        else{
          Serial.println("Point C was incorrect");
          check = 0;
        }
      }
      else{
        Serial.println("Point B was incorrect");
        check = 0;
      }
    }
    else{
      Serial.println("Point A was incorrect");
      check = 0;
    }
  }
  
  //When the fading worked twice; you have succeeded!
  if(check == 2){
    Serial.println("Success!");
    tone(successPin, 294, 250);
    delay(250);
    noTone(successPin);
    delay(10);
    tone(successPin, 294, 250);
    delay(250);
    noTone(successPin);
    delay(10);
 
    tone(successPin, 294, 250);
    delay(250);
    noTone(successPin);
    delay(10);
    tone(successPin, 294, 250);
    delay(250);
    noTone(successPin);
    delay(50);

    tone(successPin, 262, 500);
    delay(500);
    noTone(successPin);
    delay(10);
  
    tone(successPin, 262, 500);
    delay(500);
    noTone(successPin);
    delay(50);
  
    tone(successPin, 247, 500);
    delay(500);
    noTone(successPin);
    //Play the first five parts of the "Oriental Riff"
  }
}
