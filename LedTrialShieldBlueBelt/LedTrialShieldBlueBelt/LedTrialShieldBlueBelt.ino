/*

  Led Trial Shield, Blue Belt
  (C) 2015 Thijs van Beers

*/

const int led = A0;
const int successPin = 12;

int pointA;
int pointB;
int pointC;
int check = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led,INPUT);
  pinMode(successPin,OUTPUT);
  Serial.println("Start Trial");
}

// the loop routine runs over and over again forever:
void loop() 
{
  const int sensorValue = analogRead(led);
  if(sensorValue == 0){
    delay(1000);
    pointA = analogRead(led);
    if(pointA > 0){
      delay(1550);
      pointB = analogRead(led);
      if(pointB > pointA){
        delay(1550);
        pointC = analogRead(led);
        if(pointC > 0 && pointC < pointB){
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
  
  if(check == 2){
    tone(successPin,440,1000);
  }
}
