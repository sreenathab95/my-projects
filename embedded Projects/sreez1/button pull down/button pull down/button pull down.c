/*
 * button_pull_down.c
 *
 * Created: 11/7/2019 2:20:59 PM
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
		if (i==0xff)
		{
			PORTB=0x02;
		}
		else if(i==0x7e)
		{
			PORTB=0x80;
		}
		else
		{
			PORTB=0x00;

		}
		 
    }
}