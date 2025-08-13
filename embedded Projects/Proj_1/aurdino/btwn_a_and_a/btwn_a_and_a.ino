int f=0,k=0;
char b[50];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a=Serial.read();
   if(a=='a')
   {
    f++;
   }
   if(f==1) 
   {
    b[k++]=a;
   }
   if(f==2)
   {
    Serial.println(b);
    f=0;
   }
  }
  

}
