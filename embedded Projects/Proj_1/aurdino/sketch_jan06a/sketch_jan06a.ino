int h=0;
void setup() {
  pinMode(5,OUTPUT);

}

void loop() {
int i=0;
if(h==0)
{
  
h=1;
for(i=0;i<10;i++)
{
digitalWrite(5, HIGH);
  delay(1000);
digitalWrite(5,LOW);
  delay(1000);
}
}

}
