#include <avr/io.h>
char receive(void);
void transmit(char t);
void command(char c);
void data(char d);
void display(const char *s);
void delay(char x);
void serialtx(const char*p);
char keypad();
int main(void)
{
	DDRA=0xf0;
	DDRB=0x00;
	PORTB=0xff;
	PORTA=0xff;
	DDRC=0XFF;
	DDRD=0XFF;
	command(0x38);
	command(0x06);
	command(0x0C);
	command(0x80);
	command(0x01);
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x06;
	UBRRL=0x19;
	UBRRH=0x00;
	char k[50];
	int s=0,d=0;
    while(1)
    {
		if(d==0)
		{
 		serialtx("DIAL THE NUMBER");
 		transmit(0x0d);
 		for (s=0;s<10;s++)
 		{
 			k[s]=keypad();
 			transmit(k[s]);
 			delay(30);
 		}
		d=1;
		}		
		if(d==1)
		{
			
				char i=PINB;
				i=i&0xff;
			  if(i==0xfe)
			  {
				transmit(0x0d);
				serialtx("AT+CMGS=");
				serialtx("\"");
				for (s=0;s<10;s++)
				{
					transmit(k[s]);
					delay(10);
				}
				serialtx("\"");
				transmit(0x0d);
				serialtx("haaaai");
				d=2;
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
  char keypad()
	   {
	  	 delay(70);
	  	 char f=0,h;
	  	 int i;
	  	 
	  	 while(1)
	  	 {
	  		
	  		PORTA=0x7F;
	  		i=PINA;
	  		i=i&0X0F;
	  		if(i==0x0E)
	  		{
	  			h='/';
	  			f=1;
	  				
	  			}
	  		 if(i==0x0D)
	  			{
	  				h='*';
	  				f=1;
	  			}
	  		 if(i==0X0B)
	  			{
	  				h='-';
	  				f=1;
	  			}
	  		 if(i==0x07)
	  			{
	  				h='+';
	  				f=1;
	  			}
	  							
	  	PORTA=0xBF;
	  		i=PINA;
	  		i=i&0X0F;
	  		if(i==0x0E)
	  		{
	  			h='9';
	  			f=1;
	  				
	  			}
	  			 if(i==0x0D)
	  			{
	  				h='6';
	  				f=1;
	  				
	  			}
	  			if(i==0X0B)
	  			{
	  				h='3';
	  				f=1;
	  				
	  			}
	  			if(i==0x07)
	  			{
	  				h='=';
	  				f=1;
	  				
	  			}
	  	PORTA=0xDF;
	  		i=PINA;
	  		i=i&0X0F;
	  		if(i==0x0E)
	  		{
	  			h='8';
	  			f=1;
	  			
	  			}
	  			 if(i==0x0D)
	  			{
	  				h='5';
	  				f=1;
	  				
	  			}
	  			 if(i==0X0B)
	  			{
	  				h='2';
	  				f=1;
	  			}
	  			 if(i==0x07)
	  			{
	  				h='0';
	  				f=1;
	  			}
	  							
	  	
	  	PORTA=0xEF;
	  		i=PINA;
	  		i=i&0X0F;
	  		if(i==0x0E)
	  		{
	  			h='7';
	  			f=1;
	  			
	  		}			
	  			if(i==0x0D)
	  			{
	  				h='4';
	  				f=1;
	  				
	  			}
	  			 if(i==0X0B)
	  			{
	  				h='1';
	  				f=1;
	  			   
	  			}
	  			 if(i==0x07)
	  			{
	  				h='C';
	  				f=1;
	  			}
	  									
	  			if(f==1)
	  			return(h);
	  		}
	  	 			
	  	 }	