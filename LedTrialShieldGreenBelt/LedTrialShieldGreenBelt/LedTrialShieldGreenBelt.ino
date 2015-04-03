/*

  Led Trial Shield, Green Belt
  (C) 2015 Thijs van Beers and Richel Bilderbeek

*/

//Pins of the piezo and RGB LED
const int successPin = 13;
const int green = A0; 
const int red = 12;
const int blue = 11;

void setup()
{
  Serial.begin(9600);
  Serial.println("Trial1 start");
  //The piezo is an output and RGB LED an input
  pinMode(successPin,OUTPUT);
  pinMode(green,INPUT);
  pinMode(red,INPUT);
  pinMode(blue,INPUT);
}

// States:
// 0: red
// 1: green
// 2: orange
// 3: as 0
// 4: as 1
// 5: as 2

//Returns if it was successfull
bool StateZero()
{
  int count = 0;
  while (digitalRead(red) == HIGH && digitalRead(blue) == LOW && digitalRead(green) == LOW)
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

bool StateOne()
{
  int count = 0;
  while (digitalRead(red) == LOW && digitalRead(blue) == LOW && digitalRead(green) == HIGH)
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

bool StateTwo()
{
  int count = 0;
  while (digitalRead(red) == HIGH && digitalRead(blue) == LOW && analogRead(green) < 768 && analogRead(green) > 255)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateTwo: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateTwo: lasted too short");
    return false;
  }
  return true;  
}

// All states must last approximately one second
void loop()
{
  //Start when it's red
  if (digitalRead(red) == HIGH && digitalRead(blue) == LOW && digitalRead(green) == LOW)
  {
    //Check all states
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
    Serial.println("2: Start StateTwo");
    {
      const bool success = StateTwo();
      if (!success) return;
    }
    Serial.println("3: Start StateZero");
    {
      const bool success = StateZero();
      if (!success) return;
    }
    Serial.println("4: Start StateOne");
    {
      const bool success = StateOne();
      if (!success) return;
    }
    Serial.println("5: Start StateTwo");
    {
      const bool success = StateTwo();
      if (!success) return;
    }
    //SUCCESS!
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
    //Play the first four parts of the "Oriental Riff"
  }
  delay(100);
}
