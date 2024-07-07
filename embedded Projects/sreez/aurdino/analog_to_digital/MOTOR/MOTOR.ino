#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int f=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(11,OUTPUT);
  

}

void loop() {
  int a=analogRead(A0);
  Serial.println(a);
  delay(1);
  int b=analogRead(A1);
  Serial.println(b);
  delay(1);
//  
//  if(a>500&&f==0)
//  {
//    f=1;
//  }
  if(a>500&&b>500)
  {
    analogWrite(11,255);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(100);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    f=2;
  }
//  if(a<500&&f==2)
//  {
//   f=3;  
//  }
  if(a<500&&b<500)
  {
    analogWrite(11,55);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
  }
  if(a>500&&b<500)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(100);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
  }
  if(b>500&&a<500)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    
     
  }
}
