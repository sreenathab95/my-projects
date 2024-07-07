/*
 * _1_to_10_numbers.c
 *
 * Created: 11/23/2019 10:20:36 AM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);
void command(char c);
void data(char d);
void display(const char *s);
int main(void)
{
	DDRC=0xff;
	DDRD=0xff;
	command(0x38);
	command(0x80);
	command(0x0c);
	command(0x06);
	command(0x01);
    while(1)
    {
       int a=0,i=15,b=0,c=0;
	   for (a=0;a<=i;a++)
	   {
		 command(0x80);
		 display("    ");
		 if (a>=10)
		 {
			 b=a/10;
			 c=a%10;
			 command(0x80);
			 display("    ");
			 data(b+0x30);
			 data(c+0x30);
			 command(0x80);
			 display("    ");
			 continue;
		 }
		 data(a+0x30);
		 delay(10);		 		 
		 display("  ");	
	   }
	   break;		
		  
    }
}
void delay(int x)
{
	int i,j;
	for (i=0;i<=x;i++)
	for(j=0;j<=1000;j++);
	
}
void command(char c)
{
	PORTC=c;
	PORTD&=~(1<<6);
	PORTD|=(1<<7);
	delay(2);
	PORTD&=~(1<<7);
}
void data(char d)
{
	PORTC=d;
	PORTD|=(1<<6);
	PORTD|=(1<<7);
	delay(2);
	PORTD&=~(1<<7);
}
void display(const char *s)
{
	while(*s)
	{
		data(*s++);
		delay(2);
	}
}	
