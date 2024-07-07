/*
 * led_blinking.c
 *
 * Created: 11/5/2019 2:16:06 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);

int main(void)
{
   DDRA=0xff;
    while(1)
    {
		int i ;
		char c=0x01;
		char d=0x80;
		for (i=0;i<=7;i++)
		{
			char e=c+d;
			PORTA=e;
			c=c<<1;
			
			d=d>>1;
			
			delay(10);		
			
		}
		
		
		
		
                                                                                                           
	}    
}
void delay(int x)
{
	int i,j;
	for(i=0;i<=x;i++)
	 for(j=0;j<=1000;j++);
}