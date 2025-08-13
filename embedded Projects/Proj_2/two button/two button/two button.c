/*
 * two_button.c
 *
 * Created: 11/12/2019 2:24:57 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void display(const char *s);
void delay(int x);
void  command (char c);
void data(char d);
int main(void)
{
    DDRC=0xff;
	DDRD=0xff;
	command(0x38);
	command(0x80);
	command(0x0c);
	command(0x06);
	command(0x01);
	while (1)
	{
		command(0x80);
		data('a');
		command(0xc0);
		display("srenath");
	}
	   
}
void command(char c)
{
	PORTC=c;
	PORTD=~(1<<6);
	PORTD=(1<<7);
	delay(2);
	PORTD=~(1<<7);
	
}
void data(char d)
{
	PORTC=d;
	PORTD=(1<<6);
	PORTD=(1<<7);
	delay(2);
	PORTD=~(1<<7);
}
void display(const char *s)
{
	while (*s)
	{
		data(*s++);
		delay(2);
	}
}
void delay(int x)
{
	int i,j;
	for(i=0;i<=x;i++)
	 for(j=0;j<=1000;j++);
}