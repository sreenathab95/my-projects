int f=0,k=-1;
char b[50];
void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0)
  {
    char a=Serial.read();
  s: if(a=='a'&&f==0)
   {
    f++;
   }
   if(f==1) 
   {
    b[k++]=a;
    
   }
   if(a=='b')
   {
  b[k]='\0';
    Serial.println(b);
    
   }
//   else if(a=='a'&&f==2)
//   {
//    f=0;
//    goto s;
//   }
  }
}
