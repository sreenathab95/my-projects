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
  if(a>0)
  {
    digitalWrite(9,HIGH);
  }
  else if(a==0)
  {
    digitalWrite(9,LOW);
  }
}
