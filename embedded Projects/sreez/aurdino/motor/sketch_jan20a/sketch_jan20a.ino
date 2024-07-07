int f=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a=analogRead(A0);
  Serial.println(a);
  delay(1);
  int b=analogRead(A1);
  Serial.println(b);
  delay(1);
  
}
