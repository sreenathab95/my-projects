#include <avr/io.h>
char receive(void);
void transmit(char t);
void command(char c);
void data(char d);
void display(const char *s);
void delay(char x);
void serialtx(const char*p);
char a1;
int main(void)
{
	DDRC=0XFF;
	DDRD=0XFF;
	command(0x38);
	command(0x06);
	command(0x0C);
	command(0x80);
	command(0x01);
	char a,b,c[50],c1;
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x06;
	UBRRL=0x19;
	UBRRH=0x00;

    while(1)
    {
		s2: a=receive();
		if (a=='a')
		{
		s0:	 a1=receive();
			if(a1=='a')
			{
			goto s0;
			}
			if (a1=='b')
			{
							
				while(1)
				{
					s1:c[b]=receive();
					s4:if(c[b]=='a')
					{
						b++;
						c[b]=receive();
						if (c[b]=='b')
						{
							b=0;
							/*b++;*/
							goto s1;
						}
 						else 
 						{
 							goto s4;
 						}
					}
				if(c[b]=='c')					
					{
						s3:
						c1=receive();
						if(c1=='d')
						{		
							c[b]='\0';
							command(0x80);
							display(c);
							break;
						}
						if(c1=='c')
						{
							b++;
							c[b]=c1;
						//	command(0xc0);
						//	data(c[b]+0x30);
							goto s3;
						}								
						if(c1!='c'&&c1!='d')
						{
							b++;
							c[b]=c1;
							//b++;
						}							
							
					}
	
					b++;
					goto s1;
						}
					}																
				}									
			else
			{
				goto s2;
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
			
