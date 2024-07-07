/*
 * led.c
 *
 * Created: 11/4/2019 2:41:07 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);
int main(void)
{
	DDRA=0xff;
    while(1)
    {  
     int i;    
	 char c=0X01;
	for(i=0;i<=7;i++)
	{
      PORTA=c;
	  c=c<<1;
	  delay(20);
	}
    }
}
void delay(int x)
{
	int i,j;
	for(i=0;i<=x;i++)
	  for(j=0;j<=1000;j++);
	 
}