int f=0;
void setup() {
    Serial.begin(9600);

}

void loop() {
  if(f==0)
  {
    f=1;
 int a = analogRead(A0);
 Serial.println(a);
 delay(1);
 int b = analogRead(A1);
 Serial.println(b);
 delay(1);
 int c = analogRead(A2);
 Serial.println(c);
 delay(1);
 int d = analogRead(A3);
 Serial.println(d);
 delay(1);
  int e= analogRead(A4);
 Serial.println(e);
 delay(1);
 if(a>500)
 {
  if(b>500)
  {
    if(c>500)
    {
      if(d>500)
      {
        if(e>500)
        {
          Serial.println("arya");
          delay(1);
        
        }
      }
    }
  }
 }
  }

}
