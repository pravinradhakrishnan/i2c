#include<Wire.h>

int Button1 = 13;
int pot1 = A0; 
int pot2 = A1; 
int potVal1 = -1;
int potVal2 = -1;
int motorVal = -1;





void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(Button1, INPUT_PULLUP);
}

void loop()
{
 
  function1();
  function2();
}

void function1()
{
 potVal1 = analogRead(pot1);
 Wire.beginTransmission(17);
 Wire.write(potVal1);
 Wire.endTransmission();
 delay(500);
}
void function2()
{
 if(digitalRead(Button1) == 0)
  {
    Serial.write('1');
  }
  delay(20); 
}
