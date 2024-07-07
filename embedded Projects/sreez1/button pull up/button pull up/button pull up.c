/*
 * button_pull_up.c
 *
 * Created: 11/7/2019 2:00:46 PM
 *  Author: Student
 */ 

#include <avr/io.h>

int main(void)
{
	DDRA=0x00;
	DDRB=0xff;
	PORTA=0xff;
    while(1)
    {
       char i=PINA;
	   i=i&0xff;
	   if(i==0xfe)
	   {
		   PORTB=0xff;
	   }
	   else
	   {
		   PORTB=0x00;
	   }
    }
	
}