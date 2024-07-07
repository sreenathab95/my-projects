/*
 * button_without_grnd.c
 *
 * Created: 11/23/2019 11:59:29 AM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);
void command(char c);
void data(char d);
void display(const char *s);

int main(void)
{
	 DDRA=0xf0;
		DDRC=0xff;
		DDRD=0xff;
		command(0x38);
		command(0x80);
		command(0x0c);
		command(0x06);
		command(0x01);
        while(1)
        {
	    PORTA=0x7f;
		char i=PINA;
		i=i&0xff;
		if(i==0x7e)
		{
			command(0x80);
			data('7');
		}
			if(i==0x7d)
		{
			command(0x80);
			data('4');
		}
			if(i==0x7b)
		{
			command(0x80);
			data('1');
		}
			if(i==0x77)
		{
			command(0x80);
			data('c');
		}	
		PORTA=0xbf;
		char j=PINA;
		j=j&0xff;
		command(0x80);
		if (j==0xbe)
		{
			display("8");
		}
		if (j==0xbd)
		{
			display("5");
		}
		if(j==0xbb)
		{
			display("2");
		}
		if (j==0xb7)
		{
			display("0");
		}
		PORTA=0xef;
		char k=PINA;
		k=k&0xff;
		command(0x80);
		if (k==0xee)
		{
			display("9");
		}
		if (k==0xed)
		{
			display("6");
		}
		if (k==0xeb)
		{
			display("3");
		}
		if (k==0xe7)
		{
			display("=");
		}
		PORTA=0xdf;
		char l=PINA;
		l=l&0xff;
		command(0x80);
		if (l==0xde)
		{
			display("/");
		}
		if (l==0xdd)
		{
			display("*");
		}
		if (l==0xdb)
		{
			display("-");
		}
		if (l==0xd7)
		{
			display("+");
		}
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