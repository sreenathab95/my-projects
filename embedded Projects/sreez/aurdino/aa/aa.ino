int f=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a=Serial.read();
    if(a=='a'&&f==0)
    {
      analogWrite(11,10);
      f=1;
    }
   else if(f==1&&a=='a')
    {
      analogWrite(11,50);
      f=2; 
    }
   else if(f==2&&a=='a')
    {
      analogWrite(11,100);
      f=3; 
    }
    else if(f==3&&a=='a')
    {
      analogWrite(11,150);
      f=4; 
    }
       else if(f==4&&a=='a')
    {
      analogWrite(11,200);
      f=5; 
    }
     else if(f==5&&a=='a')
    {
      analogWrite(11,255);
      f=6; 
    }






     if(a=='b'&&f==6)
    {
      analogWrite(11,200);
      f=7;
    }
   else if(f==7&&a=='b')
    {
      analogWrite(11,150);
      f=8; 
    }
   else if(f==8&&a=='b')
    {
      analogWrite(11,100);
      f=9; 
    }
    else if(f==9&&a=='b')
    {
      analogWrite(11,50);
      f=10; 
    }
       else if(f==10&&a=='b')
    {
      analogWrite(11,10);
      f=0;

    }
   


  }
  

}
