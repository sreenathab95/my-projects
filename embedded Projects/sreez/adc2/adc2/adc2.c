#include <avr/io.h>
void command(char c);
void data(char d);
void delay(int x);
void display(const char *s);
void adc_1();
void adc_2();
void adc_3();
char b,b1,b2,e1,e2,e3,l,a2=0,a3=0,a4=0,a5=0,a6=0,a7;
int main(void)
{
	
	DDRC=0XFF;
	DDRD=0XFF;
	command(0x38);
	command(0x06);
	command(0x0C);
	command(0x80);
	command(0x01);
	delay(50);
	ADCSRA=0X87;
	while(1)
	{
		 adc_1();
		 adc_2();
		adc_3();
		command(0xca);
		data(a2+0x30);
		data(a3+0x30);
		data(a4+0x30);
		data(a5+0x30);
		if(b>200&&a2==0&&a3==0&&a4==0&&a5==0)
		{
			a2=1;
			command(0xc0);
			display("first    ");
		}
		if(b<200)
		{
			a2=0;
		}
		if(b1>200&&a2==1&&a4==0)
		{
			a4=1;
			command(0xc0);
			display("second");
		}
		if(b1>200&&b2>200&&a2==0&&a5==0)
		{
			a3=1;

		}		
		if(b1<200)
		{
			a3=0;
		}
		if(b2>200&&a2==1&&a4==1)
		{
			command(0xc0);
			display("3rd       ");
		}
		if(b2>200&&b1>200&&a2==0&&a3==0)
		{
			a5=1;
			a3=1;
			command(0xc0);
			display("         ");
		}
		if(b>200&&b2>200&&a4==0)
		{
			a4=1;
			
			command(0xc0);
			display("         ");
		}
		if(b2<200)
		{
			a4=0;
			a5=0;
		}
	}		
}	

void adc_1()
{
	ADMUX=0X61;
	command(0X80);
	ADCSRA|=(1<<6);
	while((ADCSRA&(1<<ADIF))==0);
	b=ADCH;
	e1=b%10;
	e2=b/10;
	e3=e2%10;
	l=e2/10;
	data(l+0x30);
	data(e3+0x30);
	data(e1+0x30);
}	
void adc_2()
{
	ADMUX=0X62;
	command(0X86);
	ADCSRA|=(1<<6);
	while((ADCSRA&(1<<ADIF))==0);
	b1=ADCH;
	e1=b1%10;
	e2=b1/10;
	e3=e2%10;
	l=e2/10;
	data(l+0x30);
	data(e3+0x30);
	data(e1+0x30);
}
void adc_3()
{
	ADMUX=0X67;
	command(0X8b);
	ADCSRA|=(1<<6);
	while((ADCSRA&(1<<ADIF))==0);
	b2=ADCH;
	e1=b2%10;
	e2=b2/10;
	e3=e2%10;
	l=e2/10;
	data(l+0x30);
	data(e3+0x30);
	data(e1+0x30);
}	
void display (const char *s)
{
	while(*s)
	{
		data(*s++);
		delay(2);
	}
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
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++)
	for(j=0;j<1000;j++);
}