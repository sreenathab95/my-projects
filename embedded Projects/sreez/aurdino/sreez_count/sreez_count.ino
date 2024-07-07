#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int f=0,b=0;
void setup() {
Serial.begin(9600);
 lcd.begin(16, 2);
  lcd.setCursor(0,0);
}

void loop() {
   lcd.setCursor(0,1); 
//   lcd.print(millis() / 1000);
if(Serial.available()>0)
{
  char a=Serial.read();
s:  if(a=='s')
  {
    f++;
  }
  if(a=='r'&&f==1)
  {
    f++;
  }
//  else 
//  {
//    f=0;
//    goto s;
//  }
  if(a=='e'&&f==2)
  {
    f++;
  }
//  else 
//  {
//    f=0;
//  }
  if(a=='e'&&f==3)
  {
    f++;
  }
//  else 
//  {
//    f=0;
//  }
  if(a=='z'&&f==4)
  {
    f=0;
    b++;
    lcd.print(b);
  }
  

}

}
