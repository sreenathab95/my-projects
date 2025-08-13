/*
 * _7_segment_display_common_anode.c
 *
 * Created: 11/6/2019 2:55:09 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);

int main(void)
{
    DDRC=0xff;
    while(1)
	{
      PORTC=0x40;
	  delay(20);
	  
	  PORTC=0xf9;
	  delay(20);
	  
	  PORTC=0xa4;
	  delay(20);
	
	  PORTC=0xb0;
	  delay(20);
	 
	  PORTC=0x99;
	  delay(20);
	
	  PORTC=0x92;
	  delay(20);
	
	  PORTC=0x82;
	  delay(20);
     
	  PORTC=0xd8;
	  delay(20);

	  PORTC=0x00;
	  delay(20);
	
	  PORTC=0x90;
	  delay(20);
	 
		  
	}	  
	  
    
}
void delay(int x)
{
	int i,j;
	for(i=0;i<=x;i++)
	for(j=0;j<=1000;j++);
	

}