
#include <avr/io.h>
void delay(int x);
void command(char c);
void data(char d);
void display(const char *s);
char kepad();

int main(void)
{
	DDRA=0xf0;
	DDRB=0x00;
	DDRC=0xff;
	DDRD=0xff;
	PORTB=0xff;
	int d=0,e=0,f=0,g=0,h=0,n=0,p=0,q=0;
	char k1,k2,k3,k4,k5;
	command(0x38);
	command(0x80);
	command(0x0c);
	command(0x06);
	command(0x01);	
	int price=0;
    while(1)
    {
		
	  if(d==0)
	    {
			command(0x80);
		   display("Do you want pen?");
		   command(0xc0);
		   display("price=10");
		  char i=PINB;
			i=i&0xff;
		   if (i==0xfe&&d==0)
		   {
			   command(0xc0);
			   display("       ");
			   command(0xc0);
			   display("yes");
			    command(0xc0);
			   display("   ");
			   d=1;
			   e=1;
			  display("how many?");
			 command(0x80);			 
	        k1=kepad();
			command(0xc0);
			display("            ");
			command(0XC0);  
		    data(k1);
			k1=k1-0x30;
		   }
		   if (i==0xfd&&d==0)
		   {
			   command(0xc0);
			   display("no");
			   command(0xc0);
			   display("         ");
			   d=1;
			   e=2;
		   }
		}
	  
	   if(d==1)
	   {  
			command(0x80);
			display("Do you want book");
			command(0xc0);
		   display("price=20");
		   char j=PINB;
			j=j&0xff;
		    if(j==0xfe&&d==1)
			{
			    command(0xc0);
				display("       ");
				command(0xc0);
			   display("yes");
			    command(0xc0);
			   display("   ");
			   d=2;
			   f=1;
			 display("how many?");
			 command(0x80);
	        k2=kepad();
			command(0xc0);
			display("            ");
			command(0XC0); 
		    data(k2);
		    k2=k2-0x30;  
		   }
		   if (j==0xfd&&d==1)
		   {
			    command(0xc0);
			   display("no");
			         command(0xc0);
			   display("        ");
			   d=2;  
			   f=2;
		   }
	   }	
	   if(d==2)
	   {
		command(0x80);
		display("do you want bag");
		 command(0xc0);
		  display("price=30");
		char k=PINB;
		k=k&0xff;
		 if (k==0xfe&&d==2)
		  {
		    command(0xc0);
			display("     ");
			command(0xc0);
			display("yes");
			command(0xc0);
			display("    ");
		    d=3;  
			g=1;
			 display("how many?");
			 command(0x80);
	        k3=kepad();
			command(0xc0);
			display("            ");
			command(0XC0); 
			data(k3);
		    k3=k3-0x30;  
						    
		  }
	     if(k==0xfd&&d==2)
	      {
		    command(0xc0);
			display("no");
			command(0xc0);
			display("        ");
		   d=3;
		   g=2;
	      }
	   } 		
	
	  if(d==3)
	   {
		command(0x80);
		display("do you want pencil");
		 command(0xc0);
		 display("price=10");
		char l=PINB;
		l=l&0xff;
		 if (l==0xfe&&d==3)
		 {
		    command(0xc0);
			display("       ");
			command(0xc0);
			display("yes");
			command(0xc0);
			display("   ");
			d=4;
			h=1;
			display("how many?");
			 command(0x80);
	        k4=kepad();
			command(0xc0);
			display("            ");
			command(0XC0); 
		    data(k4);
		    k4=k4-0x30;  
		 }
	    if(l==0xfd&&d==3)
	    {
		  command(0xc0);
		  display("no");
		  command(0xc0);
		  display("         ");
		   d=4;
		   h=2;
	    }
	   }
	   
	  if(d==4)
	   {
		command(0x80);
		display("do you want scale");
		command(0xc0);
		display("price=15");
		char m=PINB;
		m=m&0xff;
		 if (m==0xfe&&d==4)
		 {
		  command(0xc0);
		  display("        ");
		  command(0xc0);
		  display("yes");
		  command(0xc0);
		  display("   ");
		  d=5;
		  n=1;
			display("how many?");
			 command(0x80);
	        k5=kepad();
			command(0xc0);
			display("            ");
			command(0XC0); 
		       data(k5);
		    k5=k5-0x30;
		 }
	     if(m==0xfd&&d==4)
	     {
		 command(0xc0);
		 display("no");
	     command(0xc0);
		 display("           ");
		 d=5;
		 n=2;
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
			   display("pen  ");
			   command(0xc0);
			   display("            ");
			   price=price+(k1*10);
			   
		   }
		   if (f==1)
		   {
			   command(0xc0);
			   display("book ");
			   command(0xc0);
			   display("         ");
			   price=price+(k2*20);
			  
			   
		   }
		   if (g==1)
		   {
			   command(0xc0);
			   display("bag    ");
			    command(0xc0);
			   display("        ");
			   price=price+(k3*30);
			   
		   }
		   if(h==1)
		   {
			   command(0xc0);
			   display("pencil");
			    command(0xc0);
			   display("          ");
			   price=price+(k4*10);
			   
		   }
		   if (n==1)
		   {
			   command(0xc0);
			   display("scale ");
			     command(0xc0);
			   display("            ");
			    price=price+(k5*15);
			   			   
		   }
		   d=6;  
	   }
	   if (d==6)
	   {
		   command(0x80);
		   display("   ");
		   command(0x80);
		   display("total amount         ");
		   command(0xc0);
		   char a1=price/100;
		   char a2=price%100;
		   char a3=a2/10;
		   char a4=a2%10;
		   command(0xc0);
		   data(a1+0x30);
		   data(a3+0x30);
		   data(a4+0x30);
		   
		   
	
		   d=7;
		   
		  
		   
	   }
		
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