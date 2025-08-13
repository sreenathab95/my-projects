int relay1=8;
int relay2=9;
int relay3=10;
int f=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(relay1,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a=Serial.read();
    if(a=='a')
    {
      digitalWrite(8,HIGH);

    }
    else if(a=='b')
    {
      digitalWrite(8,LOW);

    }
    else if(a=='c')
    {
      digitalWrite(9,HIGH);

    }
    else if(a=='d')
    {
      digitalWrite(9,LOW);

    }
    else if(a=='e')
    {
      digitalWrite(10,HIGH);

    }
    else if(a=='f')
    {
      digitalWrite(10,LOW);

    }
  }

}
