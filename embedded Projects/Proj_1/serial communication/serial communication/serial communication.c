#include <avr/io.h>
char receive(void);
void transmit(char t);
void command(char c);
void data(char d);
void display(const char *s);
void delay(char x);
void serialtx(const char*p);
int main(void)
{
	DDRC=0XFF;
	DDRD=0XFF;
	command(0x38);
	command(0x06);
	command(0x0C);
	command(0x80);
	command(0x01);
	char a,b,c[50];
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x06;
	UBRRL=0x19;
	UBRRH=0x00;

    while(1)
    {
		char a=receive();
// 		if (a=='a')
// 		{
// 			s1:c[b]=receive();
// 			if (c[b]=='a')
// 			{
// 				c[b]='\0';
// 				command(0x80);
// 				display(c);
// 			}
// 			b++;
// 			goto s1;
// 		}
		if (a=='a')
		{
			while(1)
			{
				if (a=='a')
				{
					c[b]=receive();
					if (c[b]=='a')
						{
							c[b]='\0';
							command(0x80);
							display(c);
							break;
						}
						b++;
				}
			}
		}
		
	}
	
}
char receive()
{
	UCSRA&=~(1<<RXC);
	while((UCSRA&(1<<RXC))==0);
	return(UDR);
}
void transmit(char t)
{
	UDR=t;
	while((UCSRA&(1<<UDRE))==0x00);
}
void serialtx(const char*p)
{
	while(*p)
	{
		transmit(*p++);
		delay(2);
	}
}
void delay(char x)
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
void display (const char *s)
{
	while(*s)
	{
		data(*s++);
		delay(2);
	}
}	
			
