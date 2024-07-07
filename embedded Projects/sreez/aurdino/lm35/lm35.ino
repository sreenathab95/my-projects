float ac,af;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,INPUT);

}

void loop()
{
  float a=analogRead(A1);
  ac=(a*4.88)/10;
  Serial.println("degree celcius=");
  Serial.println("\t");
  Serial.println(ac);
   Serial.println("\t");
  af=(ac*9/5)+32;
  Serial.println("farenheit=");
  Serial.println("\t");
  Serial.println(af);
  Serial.println();
  delay(1000);
}
