/*
 * _7segmant_display.c
 *
 * Created: 11/6/2019 2:24:17 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay (int x);

int main(void)
{ 
	DDRC=0xff;
    while(1)
    {
	   PORTC=0xbf;
	   delay(20);
	   PORTC=0x00;
       PORTC=0x06;
	   delay(20);
	   PORTC=0x00;
	   PORTC=0x5b;
	   delay(20);
	   PORTC=0x00;
	   PORTC=0x4f;
	   delay(20);
	   PORTC=0x00;
	   PORTC=0x66;
	   delay(20);
	   PORTC=0x00;
	   PORTC=0x6d;
	   delay(20);
	   PORTC=0x00;
	   PORTC=0x7d;
	   delay(20);
	   PORTC=0x00;
	   PORTC=0x27;
	   delay(20);
	   PORTC=0x00;
	   PORTC=0xff;
	   delay(20);
	   PORTC=0x00;
	   PORTC=0x6f;
	   delay(20);
	   PORTC=0x00;
	   
    }
}
void delay(int x)
{
	
int i,j;
for(i=0;i<=x;i++)
 for(j=0;j<=1000;j++);
}
