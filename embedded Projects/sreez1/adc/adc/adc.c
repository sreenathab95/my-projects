/*
 * adc.c
 *
 * Created: 12/5/2019 3:49:52 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);
void command(char c);
void data(char d);
void display(const char *s);
char kepad();

int main(void)
{
	DDRC=0xff;
	DDRD=0xff;
	ADMUX=0x62;
	ADCSRA=0x87;
	command(0x38);
	command(0x80);
	command(0x0c);
	command(0x06);
	command(0x01);
	//data('a');
    while(1)
    {
        ADCSRA|=(1<<ADSC);
		while((ADCSRA&(1<<ADIF))==0);
		char i=ADCH;
		char b1=i%10;
		char b2=i/10;
		char b3=b2%10;
		char b4=b2/10;
		command(0x80);
		data(b4+0x30);
		data(b3+0x30);
		data(b1+0x30);
		delay(10);
    }
}
char kepad()
{
	delay(2);
	int t=0;
	char s;
	while (1)
	{
	    PORTA=0x7f;
		char i=PINA;
		i=i&0xff;
		if(i==0x7e)
		{
			s='7';
			t=1;
		}
			if(i==0x7d)
		{
			s='4';
			t=1;
		}
			if(i==0x7b)
		{
			s='1';
			t=1;
		}
			if(i==0x77)
		{
			s='c';
			t=1;
		}
			
        PORTA=0xbf;
		char j=PINA;
		j=j&0xff;
		if (j==0xbe)
		{
			s='8';
			t=1;
		}
		if (j==0xbd)
		{
			s='5';
			t=1;
		}
		if(j==0xbb)
		{
			s='2';
			t=1;
		}
		if (j==0xb7)
		{
			s='0';
			t=1;
		}
		
        PORTA=0xef;
		char k=PINA;
		k=k&0xff;
		if (k==0xee)
		{
			s='9';
			t=1;
		}
		if (k==0xed)
		{
			s='6';
			t=1;
		}
		if (k==0xeb)
		{
			s='3';
			t=1;
		}
		if (k==0xe7)
		{
			s='=';
			t=1;
		}

		PORTA=0xdf;
		char l=PINA;
		l=l&0xff;
		if (l==0xde)
		{
			s='/';
			t=1;
		}
		if (l==0xdd)
		{
			s='*';
			t=1;
		}
		if (l==0xdb)
		{
			s='-';
			t=1;
		}
		if (l==0xd7)
		{
			s='+';
			t=1;
		}
		if (t==1)
		{
			return(s);
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