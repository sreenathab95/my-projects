/*
 * _7_segment_with_loop.c
 *
 * Created: 11/6/2019 3:49:25 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);

int main(void)
{ 
	DDRC=0xff;
	char a[10]={0x40,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x00,0x90};
   while(1)
    {
        int i;
		for(i=0;i<10;i++)
		{
			PORTC=a[i];
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