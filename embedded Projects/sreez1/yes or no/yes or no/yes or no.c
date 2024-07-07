/*
 * yes_or_no.c
 *
 * Created: 11/21/2019 2:03:17 PM
 *  Author: Student
 */ 

#include <avr/io.h>
void delay(int x);
void command(char c);
void data(char d);
void display(const char *s);

int main(void)
{
	DDRA=0x00;
	DDRC=0xff;
	DDRD=0xff;
	PORTA=0xff;
	int d=0,e=0,f=0,g=0,h=0,n=0;
	command(0x38);
	command(0x80);
	command(0x0c);
	command(0x06);
	command(0x01);	
    while(1)
    {
	  if(d==0)
	    {
			command(0x80);
		   display("Do you want pen?");
		  char i=PINA;
			i=i&0xff;
		   if (i==0xfe&&d==0)
		   {
			   command(0xc0);
			   display("yes");
			    command(0xc0);
			   display("   ");
			   d=1;
			   e=1;
		   }
		   if (i==0x7f&&d==0)
		   {
			   command(0xc0);
			   display("no");
			   command(0xc0);
			   display("   ");
			   d=1;
			   e=2;
		   }
		}
	  
	   if(d==1)
	   {   
			//command(0x01);
			command(0x80);
			display("Do you want book");
		   char j=PINA;
			j=j&0xff;
		    if(j==0xfe&&d==1)
			{
			    command(0xc0);
			   display("yes");
			    command(0xc0);
			   display("   ");
			   d=2;
			   f=3;
		   }
		   if (j==0x7f&&d==1)
		   {
			    command(0xc0);
			   display("no");
			         command(0xc0);
			   display("   ");
			   d=2;
			   f=4;
		   }
	   }	
	   if(d==2)
	   {
		command(0x80);
		display("do you want bag");
		command(0xc0);
		char k=PINA;
		k=k&0xff;
		 if (k==0xfe&&d==2)
		  {
		    command(0xc0);
			display("yes");
			command(0xc0);
			display("   ");
		    d=3;
			g=5; 
		  }
	     if(k==0x7f&&d==2)
	      {
		    command(0xc0);
			display("no");
			command(0xc0);
			display("   ");
		   d=3;
		   g=6;
	      }
	   } 		
	
	  if(d==3)
	   {
		command(0x80);
		display("do you want pencil");
		command(0xc0);
		char l=PINA;
		l=l&0xff;
		 if (l==0xfe&&d==3)
		 {
		    command(0xc0);
			display("yes");
			command(0xc0);
			display("   ");
			d=4;
			h=7;
		 }
	    if(l==0x7f&&d==3)
	    {
		  command(0xc0);
		  display("no");
		  command(0xc0);
		  display("   ");
		   d=4;
		   h=8;
	    }
	   }
	   
	  if(d==4)
	   {
		command(0x80);
		display("do you want scale");
		command(0xc0);
		char m=PINA;
		m=m&0xff;
		 if (m==0xfe&&d==4)
		 {
		  command(0xc0);
		  display("yes");
		  command(0xc0);
		  display("   ");
		  d=5;
		  n=9;
		 }
	     if(m==0x7f&&d==4)
	     {
		 command(0xc0);
		 display("no");
	     command(0xc0);
		 display("   ");
		 d=5;
		 n=10;
		 command(0x80);
		 display("  ");
	     }
	   }
	   if (d==5)
	   {
		   command(0x80);
		   delay(2);
		   display("selected items are");
		   if (e==1)
		   {
			   command(0xc0);
			   display("pen    ");
			   command(0xc0);
			   display("  ");
		   }
		   if (f==3)
		   {
			   command(0xc0);
			   display("book ");
			   command(0xc0);
			   display("  ");
		   }
		   if (g==5)
		   {
			   command(0xc0);
			   display("bag    ");
			    command(0xc0);
			   display("  ");
		   }
		   if(h==7)
		   {
			   command(0xc0);
			   display("pencil");
			    command(0xc0);
			   display("      ");
		   }
		   if (n==9)
		   {
			   command(0xc0);
			   display("scale ");
			     command(0xc0);
			   display("  ");
		   }
		   d=6;
		   
		   
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