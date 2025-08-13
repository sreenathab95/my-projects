void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  pinMode(11,OUTPUT);


}

void loop() {
int sensorValue=analogRead(A0);
  Serial.println(sensorValue);
  delay(1); 
}
