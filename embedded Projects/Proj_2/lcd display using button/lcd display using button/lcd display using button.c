/*
 * lcd_display_using_button.c
 *
 * Created: 11/19/2019 2:59:16 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);
void command (char c);
void data(char d);
void display(const char *s);

int main(void)
{
	DDRA=0x00;
	DDRC=0xff;
	PORTA=0xff;
	int f=0;
    while(1)
    {
      char i=PINA;
	  i=i&0xff;
	  if (i==0xfe&&f==0)
	  {
	   PORTC=0xbf;
	   f=1;
	  }
	  if (i==0xff&&f==1)
	  {
	   f=2;
	  }
	  if (i==0xfe&&f==2)
	  { 
	   f=3;
	  }
	  if (f==3)
	  {
		  PORTC=0x06;
	  }
	  if (i==0xff&&f==3)
	  {
		  f=4;
	  }
	  if (i==0xfe&&f==4)
	  { 
	   f=5;
	  }
	  if (f==5)
	  {
		  PORTC=0x5b;
	  }
	  if (i==0xff&&f==5)
	  {
		  f=6;
	  }
	  if (i==0xfe&&f==6)
	  { 
	   f=7;
	  }
	  if (f==7)
	  {
		  PORTC=0x4f;
	  }
	  if (i==0xff&&f==7)
	  {
		  f=8;
	  }
	  if (i==0xfe&&f==8)
	  { 
	   f=9;
	  }
	  if (f==9)
	  {
		  PORTC=0x66;
	  }
	  if (i==0xff&&f==9)
	  {
		  f=10;
	  }
	  if (i==0xfe&&f==10)
	  { 
	   f=11;
	  }
	  if (f==11)
	  {
		  PORTC=0x6d;
	  }
	  if (i==0xff&&f==11)
	  {
		  f=12;
	  }
	  if (i==0xfe&&f==12)
	  { 
	   f=13;
	  }
	  if (f==13)
	  {
		  PORTC=0x7d;
	  }
	  if (i==0xff&&f==13)
	  {
		  f=14;
	  }
	  if (i==0xfe&&f==14)
	  { 
	   f=15;
	  }
	  if (f==15)
	  {
		  PORTC=0x27;
	  }
	  if (i==0xff&&f==15)
	  {
		  f=16;
	  }
	  if (i==0xfe&&f==16)
	  { 
	   f=17;
	  }
	  if (f==17)
	  {
		  PORTC=0xff;
	  }
	  if (i==0xff&&f==17)
	  {
		  f=18;
	  }
	  if (i==0xfe&&f==18)
	  { 
	   f=19;
	  }
	  if (f==19)
	  {
		  PORTC=0x6f;
	  }
	  if (i==0xff&&f==19)
	  {
		  f=0;
	  }

	
	}	
	 
}
	
	
		
	