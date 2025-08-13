/*
 * _7_segment_display_increment_decrement.c
 *
 * Created: 11/20/2019 1:45:49 PM
 *  Author: Student
 */ 

#include <avr/io.h>

int main(void)	
{
	DDRA=0x00;
	DDRC=0xff;
	PORTA=0xff;
	int f=0,d=0;
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
	   if (i==0x7f&&f==2)
	   {
		   f=1;
		   PORTC=0xbf;
	   }
	   
	   if (i==0xfe&&f==2)
	   {
		  f=3;
		  PORTC=0x06;  
	   }
	
	   if (i==0xff&&f==3)
	   {
		   f=4;
	   }
	   if (i==0x7f&&f==4)
	   {
	     f=1;
		 PORTC=0xbf;
	   }
	   if (i==0xfe&&f==4)
	   {
		   f=5;
		   PORTC=0x5b;
	   }
	   if (i==0xff&&f==5)
	   {
		   f=6;
	   }
	   if (i==0x7f&&f==6)
	   {
		   f=3;
		   PORTC=0x06;
	   }
	   if (i==0xfe&&f==6)
	   {
		   f=7;
		   PORTC=0x4f;
	   }
	   if (i==0xff&&f==7)
	   {
		   f=8;
	   }
	   if (i==0x7f&&f==8)
	   {
		   f=5;
		   PORTC=0x5b;
	   }
	   if (i==0xfe&&f==8)
	   {
		   f=9;
		   PORTC=0x66;
	   }
	   if (i==0xff&&f==9)
	   {
		   f=10;
	   }
	   if (i==0x7f&&f==10)
	   {
		   f=7;
		   PORTC=0x4f;
	   }
	   if (i==0xfe&&f==10)
	   {
		   f=11;
		   PORTC=0x6d;
	   }
	   if (i==0xff&&f==11)
	   {
		   f=12;
	   }
	   if (i==0x7f&&f==12)
	   {
		   f=9;
		   PORTC=0x66;
	   }
	   if (i==0xfe&&f==12)
	   {
		   f=13;
		   PORTC=0x7d;
	   }
	   if (i==0xff&&f==13)
	   {
		   f=14;
	   }
	   if (i==0x7f&&f==14)
	   {
		   f=11;
		   PORTC=0x6d;
	   }
	   if (i==0xfe&&f==14)
	   {
		   f=15;
		   PORTC=0x27;
	   }
	   if (i==0xff&&f==15)
	   {
		   f=16;
	   }
	   if (i==0x7f&&f==16)
	   {
		   f=13;
		   PORTC=0x7d;
	   }
	   if (i==0xfe&&f==16)
	   {
		   f=17;
		   PORTC=0xff;
	   }
	   if (i==0xff&&f==17)
	   {
		   f=18;
	   }
	   if (i==0x7f&&f==18)
	   {
		   f=15;
		   PORTC=0x27;
	   }
	   if (i==0xfe&&f==18)
	   {
		   f=19;
		   PORTC=0x6f;
	   }
	    if (i==0xff&&f==19)
	   {
		   f=20;
	   }
	   if (i==0x7f&&f==19)
	   {
		   f=17;
		   PORTC=0xff;
	   }
	   if (i==0x7f&&f==20)
	   {
		   f=19;
		   PORTC=0x6f;
		   
	   }
	
	    
    }
}