#include <avr/io.h>
void delay(int x);
void command(char c);
void data(char d);
void display(const char *s);
char kepad();

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
		int k3;
        while(1)
        {
        	command(0x80);
			display("enter the first value");
			command(0xc0);
			char k1=kepad();
			data(k1);
			k1=k1-0x30;
			command(0xc1);
			char k2=kepad();
			data(k2);
			k2=k2-0x30;
			k3=(k1*10)+k2;
			
				command(0xc0);
				command(0x80);
				display("enter the second number");
				command(0xc0);
				char k4=kepad();
				data(k4);
				k4=k4-0x30;
				command(0xc1);
				char k5=kepad();
				data(k5);
				k5=k5-0x30;
				int k6=(k4*10)+k5;
			
			
			command(0x01);
			command(0x80);
			display("operator");
			char k7=kepad();
			command(0xc0);
			data(k7);
			
			if (k7=='+')
			{
				command(0x01);
				int k8=k3+k6;
				char a1=k8/100;
				char a2=k8%100;
				char a3=a2/10;
				char a4=a2%10;
				command(0xc0);
				data(a1+0x30);
				data(a3+0x30);
				data(a4+0x30);
				delay(10);
			}
			
			if (k7=='-')
			{	
				command(0x01);
				int k8=k3-k6;
				char a1=k8/100;
				char a2=k8%100;
				char a3=a2/10;
				char a4=a2%10;
				command(0xc0);
				data(a1+0x30);
				data(a3+0x30);
				data(a4+0x30);
				delay(10);
				
			}
			
			if (k7=='*')
			{	
				command(0x01);
				int k8=k3*k6;
				char a1=k8/100;
				char a2=k8%100;
				char a3=a2/10;
				char a4=a2%10;
				command(0xc0);
				data(a1+0x30);
				data(a3+0x30);
				data(a4+0x30);
				delay(10);
				
			}
			
			
			if (k7=='/')
			{	
				command(0x01);
				int k8=k3/k6;
				char a1=k8/100;
				char a2=k8%100;
				char a3=a2/10;
				char a4=a2%10;
				command(0xc0);
				data(a1+0x30);
				data(a3+0x30);
				data(a4+0x30);
				delay(10);
				
			}
					
	

			
			
	    }	
		
}
char kepad()
{
	delay(20);
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