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


void loop() 
{
  //Start when the LED is off
  const int sensorValue = analogRead(led);
  if(sensorValue == 0){
    delay(1000);
    //Point A should be one second in to the fading on, so it should be more than zero
    pointA = analogRead(led);
    if(pointA > 0){
      delay(1550);
      //Point B should be when te LED is fully on, so it should be more than point B
      pointB = analogRead(led);
      if(pointB > pointA){
        delay(1550);
        //Point C should be one second before the LED is fully off, so it should be more than zero and less than point B
        pointC = analogRead(led);
        if(pointC > 0 && pointC < pointB){
          //If it is correct add one to check, otherwise reset check
          ++check;  
        }
        else{
          check = 0;
        }
      }
      else{
        check = 0;
      }
    }
    else{
      check = 0;
    }
  }
  
  //When the fading worked twice; you have succeeded!
  if(check == 2){
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
