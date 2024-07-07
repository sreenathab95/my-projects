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
  if(a<100)
  {
    digitalWrite(9,HIGH);
  }
  else if(a>300)
  {
    digitalWrite(9,LOW);
    delay(1000);
    digitalWrite(9,HIGH);
    delay(1000);
    digitalWrite(9,LOW);
    while(1);
    
  }
}
