#include <Servo.h>
#include <Wire.h>
Servo myservo;


const int switchPin = 13;
const int forward1 = 5;
const int forward2 = 4;
const int reverse1 = 3;
const int reverse2 = 2;
int potVal1 = -1;
int val = 0;
int motVal=-1;

int switchState = 0;

void setup() 
{
 myservo.attach(9);
 pinMode(switchPin, INPUT);
 pinMode (forward1, OUTPUT);
 pinMode (forward2, OUTPUT);
 pinMode (reverse1, OUTPUT);
 pinMode (reverse2, OUTPUT);
 Wire.begin(17);
 Wire.onReceive(receiveEvent);
 Serial.begin(9600);
}

void loop() 
{

}

void receiveEvent(int howLong)
{
Serial.println();
while(Wire.available()>0)
{
  potVal1 = Wire.read();
Serial.println(potVal1);

} 

 motVal = map(potVal1,0,1023,0,255);
 switchState = digitalRead(switchPin);
 
 if (switchState == LOW) 
  {
  
   analogWrite(reverse1, motVal);
   digitalWrite (reverse2, HIGH);  
   digitalWrite (forward1, LOW);
   digitalWrite (forward2, LOW);    
  
  }
 if (switchState == HIGH) 
  {
   
   analogWrite(forward1, motVal);
   digitalWrite (forward2, HIGH);
   digitalWrite (reverse1, LOW);
   digitalWrite (reverse2, LOW);
  
  }
   
}
