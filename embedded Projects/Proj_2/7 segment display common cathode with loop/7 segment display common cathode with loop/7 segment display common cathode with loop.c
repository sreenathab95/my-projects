/*
 * _7_segment_display_common_cathode_with_loop.c
 *
 * Created: 11/6/2019 4:19:36 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);

int main(void)
{ 
	DDRC=0xff;
    while(1)
    {
       int i;
	   char a[10]={0xbf,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0xff,0x6f};
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