/*

  Led Trial Shield, White Belt
  (C) 2015 Thijs van Beers and Richel Bilderbeek

*/

const int successPin = 13;
const int pin_led1 = A0; //The pin 13 of the student

void setup()
{
  Serial.begin(9600);
  pinMode(pin_led_success,OUTPUT);
  pinMode(pin_led1,INPUT);
  Serial.println("Trial1 start");
}

// States:
// 0: led1 high,
// 1: led1 low,
// 2: as 0
// 3: as 1

//Returns if it was successfull
bool StateZero()
{
  int count = 0;
  while (digitalRead(pin_led1) == HIGH)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateZero: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateZero: lasted too short");
    return false;
  }
  return true;  
}

//Returns if it was successfull
bool StateOne()
{
  int count = 0;
  while (digitalRead(pin_led1) == LOW)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateOne: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateOne: lasted too short");
    return false;
  }
  return true;  
}

// Both states must last approximately one second
void loop()
{
  if (digitalRead(pin_led1) == HIGH)
  {
    Serial.println("0: Start StateZero");
    {
      const bool success = StateZero();
      if (!success) return;
    }
    Serial.println("1: Start StateOne");
    {
      const bool success = StateOne();
      if (!success) return;
    }
    Serial.println("2: Start StateZero");
    {
      const bool success = StateZero();
      if (!success) return;
    }
    Serial.println("3: Start StateOne");
    {
      const bool success = StateOne();
      if (!success) return;
    }
    //SUCCESS!
    tone(speaker, 294, 250);
    delay(250);
    noTone(speaker);
    delay(10);
    tone(speaker, 294, 250);
    delay(250);
    noTone(speaker);
    //Play the first part of the "Oriental Riff"
  }
  delay(100);
}
