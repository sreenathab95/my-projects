int f=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a=analogRead(A0);
  Serial.println(a);
  delay(1);
  if(a>500)
  {
    f=1;
  }
  if(f==1&&a>500)
  {
    Serial.println("sreez");
    delay(1);
  }

}
