/*

  Led Trial Shield, Brown Belt
  (C) 2015 Thijs van Beers

*/

//The pins of the piezo and the LED
const int red        = A0;
const int green      = A1;
const int blue       = A2;
const int successPin = 12;

int R[] = {0,0,0,0,0,0};
int G[] = {0,0,0,0,0,0};
int B[] = {0,0,0,0,0,0};
int check = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Start Trial");
  //The LED pins are inputs, the piezo an output
  pinMode(red,INPUT);
  pinMode(green,INPUT);
  pinMode(blue,INPUT);
  pinMode(successPin,OUTPUT);
}


void loop() 
{
  //Start when the LED is red
  const int redValue = analogRead(red);
  const int greenValue = analogRead(green);
  const int blueValue = analogRead(blue);
  
  if(redValue == 1023 && greenValue == 0 && blueValue == 0){
    delay(850);
    Serial.println("Start point 0");
    //Point 0 should be a third of the way in to fading to full green, so red should be bigger than green and green should be bigger than zero and blue should be zero
    R[0] = analogRead(red);
    G[0] = analogRead(green);
    B[0] = analogRead(blue);
    
    if(R[0] > G[0] && G[0] > 0 && B[0] == 0){
      delay(850);
      Serial.println("Start point 1");
      //Point 1 should be two thirds of the way in to fading to full green, so red should be smaller than green and red should be bigger than zero and blue should be zero
      R[1] = analogRead(red);
      G[1] = analogRead(green);
      B[1] = analogRead(blue);
      
      if(R[1] < G[1] && R[1] > 0 && B[1] == 0){
        delay(850);
        Serial.println("Start point 2");
        //Point 2 should be a third of the way in to fading to full blue, so green should be bigger than blue and blue should be bigger than zero and red should be zero
        R[2] = analogRead(red);
        G[2] = analogRead(green);
        B[2] = analogRead(blue);
        
        if(G[2] > B[2] && B[2] > 0 && R[2] == 0){
          delay(850);
          Serial.println("Start point 3");
          //Point 3 should be two thirds of the way in to fading to full blue, so green should be smaller than blue and green should be bigger than zero and red should be zero
          R[3] = analogRead(red);
          G[3] = analogRead(green);
          B[3] = analogRead(blue);
          
          if(G[3] < B[3] && G[3] > 0 && R[3] == 0){
            delay(850);
            Serial.println("Start point 4");
            //Point 4 should be a third of the way in to fading to full red, so blue should be bigger than red and red should be bigger than zero and green should be zero
            R[4] = analogRead(red);
            G[4] = analogRead(green);
            B[4] = analogRead(blue);
            
            if(B[4] > R[4] && R[4] > 0 && G[4] == 0){
              delay(850);
              Serial.println("Start point 5");
              //Point 5 should be two thirds of the way in to fading to full red, so blue should be smaller than red and blue should be bigger than zero and green should be zero
              R[5] = analogRead(red);
              G[5] = analogRead(green);
              B[5] = analogRead(blue);
              
              if(B[5] < R[5] && B[5] > 0 && G[5] == 0){
                //If everything is correct add one to check, when something is incorrect reset check
                Serial.println("All points were correct!");
                ++check;
              }
              else{
                Serial.println("Point 5 was incorrect");
                check = 0;
              }
            }
            else{
              Serial.println("Point 4 was incorrect");
              check = 0;
            }
          }
          else{
            Serial.println("Point 3 was incorrect");
            check = 0;
          }
        }
        else{
          Serial.println("Point 2 was incorrect");
          check = 0;
        }
      }
      else{
        Serial.println("Point 1 was incorrect");
        check = 0;
      }
    }
    else{
      Serial.println("Point 0 was incorrect");
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
    delay(10);
    
    tone(successPin, 247, 500);
    delay(500);
    noTone(successPin);
    //Play the first six parts of the "Oriental Riff"
  }
}
