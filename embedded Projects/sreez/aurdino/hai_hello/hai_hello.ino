int f=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a=Serial.read();
   if(a=='h')
   {
    f=1;
   }
   else if(a=='a'&&f==1)
   {
    f=2;
   }
   else if(a=='i'&&f==2)
   {
    f=3;
    Serial.println("hello");
   }
   else
   {
    f=0;
   }
   


  }
  

}
