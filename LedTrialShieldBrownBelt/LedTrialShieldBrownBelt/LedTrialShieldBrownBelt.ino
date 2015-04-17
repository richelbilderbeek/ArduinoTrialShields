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

int GetPwm(const int pin_read)
{
  const int dist_micro_sec_int = pulseIn(pin_read,HIGH);
  if (dist_micro_sec_int == 0){
    if(digitalRead(pin_read) == LOW) return 0;
    else if(digitalRead(pin_read) == HIGH) return 255;
  }
  const double dist_micro_sec = static_cast<double>(dist_micro_sec_int);
  const double period_micro_sec = (1.0 / 490.0) * (1000.0 * 1000.0); //microsecond
  const double f = dist_micro_sec / period_micro_sec; 
  const double pwm = f * 255.0;
  return static_cast<int>(pwm);
}

void loop() 
{
  //Start when the LED is red
  const int redValue = GetPwm(red);
  const int greenValue = GetPwm(green);
  const int blueValue = GetPwm(blue);
  
  if(redValue == 255 && greenValue == 0 && blueValue == 0){
    delay(850);
    Serial.println("Start point 0");
    //Point 0 should be a third of the way in to fading to full green, so red should be 170 and green 85 and blue should be 0
    R[0] = GetPwm(red);
    G[0] = GetPwm(green);
    B[0] = GetPwm(blue);
    
    if(R[0] > 160 && R[0] < 180 && G[0] > 75 && G[0] < 95 && B[0] == 0){
      delay(850);
      Serial.println("Start point 1");
      //Point 1 should be two thirds of the way in to fading to full green, so red should be 85 and green should be 170 and blue should be zero
      R[1] = GetPwm(red);
      G[1] = GetPwm(green);
      B[1] = GetPwm(blue);
      
      if(R[0] > 75 && R[0] < 95 && G[0] > 160 && G[0] < 180 && B[1] == 0){
        delay(850);
        Serial.println("Start point 2");
        //Point 2 should be a third of the way in to fading to full blue, so green should be 170 and blue 85 and red should be 0
        R[2] = GetPwm(red);
        G[2] = GetPwm(green);
        B[2] = GetPwm(blue);
        
        if(G[0] > 160 && G[0] < 180 && B[0] > 75 && B[0] < 95 && R[2] == 0){
          delay(850);
          Serial.println("Start point 3");
          //Point 3 should be two thirds of the way in to fading to full blue, so green should be 85 and blue should be 170 and red should be 0
          R[3] = GetPwm(red);
          G[3] = GetPwm(green);
          B[3] = GetPwm(blue);
          
          if(G[0] > 75 && G[0] < 95 && B[0] > 160 && B[0] < 180 && R[3] == 0){
            delay(850);
            Serial.println("Start point 4");
            //Point 4 should be a third of the way in to fading to full red, so blue should be 170 and red should be 85 and green should be 0
            R[4] = GetPwm(red);
            G[4] = GetPwm(green);
            B[4] = GetPwm(blue);
            
            if(R[0] > 75 && R[0] < 95 && B[0] > 160 && B[0] < 180 && G[4] == 0){
              delay(850);
              Serial.println("Start point 5");
              //Point 5 should be two thirds of the way in to fading to full red, so blue should be 85 and red should be 170 and green should be 0
              R[5] = GetPwm(red);
              G[5] = GetPwm(green);
              B[5] = GetPwm(blue);
              
              if(R[0] > 160 && R[0] < 180 && B[0] > 75 && B[0] < 95 && G[5] == 0){
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
