/*
 * button_1221.c
 *
 * Created: 11/14/2019 3:09:08 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);
void command(char c);
void data(char d);
void display (const char *s);
int main(void)
{
	DDRA=0x00;
	DDRB=0xff;
	PORTA=0xff;
	DDRC=0xff;
	DDRD=0xff;
	command(0x38);
	command(0x80);
	command(0x0c);
	command(0x06);
	command(0x01);
	int f=0,c=0,d=0,e=0;
    while(1)
    {
        char i=PINA;
		i=i&0xff;
		if(i==0xfe&&f==0)
		{
			f=1;
			command(0x80);
			data(f+0x30);
		}
	
		if (i==0xef&&f==1)
		{
			c=1;
			delay(10);
			command(0x82);
			data(c+0x30);
			
		}
		if (i==0xef&&c==1&&f==1)
		{
			c=2;
			command(0x84);
			data(d+0x30);
			//PORTB=0xff;
		}
		if (i==0xfe&&c==2&&e==0)
		{
			e++;
			command(0x86);
			data(e+0x30);
			PORTB=0xff;
			
		}
		//if (f==2&&c==2&&e==1)
		//{
			//PORTB=0xff;
		//}
		
    }
}
void delay(int x)
{
	
	int i,j;
	for(i=0;i<=x;i++)
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