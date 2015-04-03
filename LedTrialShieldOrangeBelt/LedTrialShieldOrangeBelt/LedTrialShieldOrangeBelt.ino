/*

  Led Trial Shield, Orange Belt
  (C) 2015 Thijs van Beers and Richel Bilderbeek

*/
//Piezo and the pins of the seven segment display
const int successPin = 12;
const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

void setup() {
  Serial.begin(9600);
  Serial.println("Trial Start");
//All the seven segment pins are inputs, the piezo is an output
  for(int i=2; i!=9; ++i){
    pinMode(i, INPUT);
  }
  pinMode(succesPin, OUTPUT);
}

//Display 0 for a second, returns true when succesfull  
bool StateZero()
{
  int count = 0;
  while (digitalRead(A) == HIGH && digitalRead(B) == HIGH && digitalRead(C) == HIGH && digitalRead(D) == HIGH && digitalRead(E) == HIGH && digitalRead(F) == HIGH && digitalRead(G) == LOW)
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

//Display 1 for a second, returns true when succesfull   
bool StateOne()
{
  int count = 0;
  while ((digitalRead(A) == LOW && digitalRead(B) == HIGH && digitalRead(C) == HIGH && digitalRead(D) == LOW && digitalRead(E) == LOW && digitalRead(F) == LOW && digitalRead(G) == LOW)
      || (digitalRead(A) == LOW && digitalRead(B) == LOW && digitalRead(C) == LOW && digitalRead(D) == LOW && digitalRead(E) == HIGH && digitalRead(F) == HIGH && digitalRead(G) == LOW))
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

//Display 2 for a second, returns true when succesfull   
bool StateTwo()
{
  int count = 0;
  while (digitalRead(A) == HIGH && digitalRead(B) == HIGH && digitalRead(C) == LOW && digitalRead(D) == HIGH && digitalRead(E) == HIGH && digitalRead(F) == LOW && digitalRead(G) == HIGH)
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
 
//Display 3 for a second, returns true when succesfull   
bool StateThree()
{
  int count = 0;
  while (digitalRead(A) == HIGH && digitalRead(B) == HIGH && digitalRead(C) == HIGH && digitalRead(D) == HIGH && digitalRead(E) == LOW && digitalRead(F) == LOW && digitalRead(G) == HIGH)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateThree: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateThree: lasted too short");
    return false;  
  }
  return true;  
}

//Display 4 for a second, returns true when succesfull    
bool StateFour()
{
  int count = 0;
    while (digitalRead(A) == LOW && digitalRead(B) == HIGH && digitalRead(C) == HIGH && digitalRead(D) == LOW && digitalRead(E) == LOW && digitalRead(F) == HIGH && digitalRead(G) == HIGH)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateFour: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateFour: lasted too short");
    return false;  
  }
  return true;  
}

//Display 5 for a second, returns true when succesfull  
bool StateFive()
{
  int count = 0;
  while (digitalRead(A) == HIGH && digitalRead(B) == LOW && digitalRead(C) == HIGH && digitalRead(D) == HIGH && digitalRead(E) == LOW && digitalRead(F) == HIGH && digitalRead(G) == HIGH)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateFive: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateFive: lasted too short");
    return false;  
  }
  return true;  
}
    
//Display 6 for a second, returns true when succesfull  
bool StateSix()
{
  int count = 0;
  while (  digitalRead(B) == LOW && digitalRead(C) == HIGH && digitalRead(D) == HIGH && digitalRead(E) == HIGH && digitalRead(F) == HIGH && digitalRead(G) == HIGH)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateSix: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateSix: lasted too short");
    return false;  
  }
  return true;  
}

//Display 7 for a second, returns true when succesfull  
bool StateSeven()
{
  int count = 0;
  while (digitalRead(A) == HIGH && digitalRead(B) == HIGH && digitalRead(C) == HIGH && digitalRead(D) == LOW && digitalRead(E) == LOW && digitalRead(F) == LOW)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateSeven: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateSeven: lasted too short");
    return false;  
  }
  return true;  
}
  
//Display 8 for a second, returns true when succesfull  
bool StateEight()
{
  int count = 0;
  while (digitalRead(A) == HIGH && digitalRead(B) == HIGH && digitalRead(C) == HIGH && digitalRead(D) == HIGH && digitalRead(E) == HIGH && digitalRead(F) == HIGH && digitalRead(G) == HIGH)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateEight: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateEight: lasted too short");
    return false;  
  }
  return true;  
}
  
//Display 9 for a second, returns true when succesfull  
bool StateNine()
{
  int count = 0;
  while (digitalRead(A) == HIGH && digitalRead(B) == HIGH && digitalRead(C) == HIGH && digitalRead(E) == LOW && digitalRead(F) == HIGH && digitalRead(G) == HIGH)
  { 
    ++count;
    if (count == 13) 
  {
    Serial.println("Fail StateNine: lasted too long");
    return false;
  }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateNine: lasted too short");
    return false;  
  }
  return true;  
}
  

void loop()
{
  //Start when a zero is displayed
  if (digitalRead(A) == HIGH && digitalRead(B) == HIGH && digitalRead(C) == HIGH && digitalRead(D) == HIGH && digitalRead(E) == HIGH && digitalRead(F) == HIGH && digitalRead(G) == LOW)
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
    Serial.println("3: Start StateThree");
    {
      const bool success = StateThree();
      if (!success) return;
    }
    Serial.println("4: Start StateFour");
    {
      const bool success = StateFour();
      if (!success) return;
    }
    Serial.println("5: Start StateFive");
    {
      const bool success = StateFive();
      if (!success) return;
    }
    Serial.println("6: Start StateSix");
    {
      const bool success = StateSix();
      if (!success) return;
    }
    Serial.println("7: Start StateSeven");
    {
      const bool success = StateSeven();
      if (!success) return;
    }
    Serial.println("8: Start StateEight");
    {
      const bool success = StateEight();
      if (!success) return;
    }
    Serial.println("9: Start StateNine");
    {
      const bool success = StateNine();
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
    delay(10);
  
    tone(speaker, 294, 250);
    delay(250);
    noTone(speaker);
    delay(10);
    tone(speaker, 294, 250);
    delay(250);
    noTone(speaker);
    delay(50);
  
    tone(speaker, 262, 500);
    delay(500);
    noTone(speaker);
    //Play the first three parts of the "Oriental Riff"
  }
  delay(100);
}

