int f=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,INPUT);
  pinMode(9,OUTPUT);

}

void loop()
{
    int a=analogRead(A1);
    Serial.println(a);
    delay(100);
   if(a<100&&f==0)
    {
      digitalWrite(9,HIGH);
      f=1;

    }
    else if(a>100)
    {
      digitalWrite(9,LOW);
      f=0;
    }
    if(Serial.available()>0)
    {
     String b=Serial.readString();
    if(b=="off"&&f==1)
      {
        digitalWrite(9,LOW);
        f=2;
      }
     
     else if(b=="on"&&f==2)
      {
         f=0;
      }
  }
}
