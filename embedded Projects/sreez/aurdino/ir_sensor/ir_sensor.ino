void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);

}

void loop()
{
  int a=analogRead(A1);
  Serial.println(a);
  delay(100);
  if(a>300)
  {
    digitalWrite(9,HIGH);
  }
  else if(a<300)
  {
    digitalWrite(9,LOW);
    delay(100);
    
  }
}
