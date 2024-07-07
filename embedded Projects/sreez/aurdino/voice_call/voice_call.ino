#include <SoftwareSerial.h>
void sendMessage();
void voicecall();
SoftwareSerial gsm(9,10);
void setup() {
  // put your setup code here, to run once:
  gsm.begin(9600);
  Serial.begin(9600);
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a=Serial.read();
    Serial.println(a);
    if(a=='a')
    {
      sendMessage();
      
    }
    else if(a=='c')
    {
      voicecall();
    }
    else if(a=='h')
    {
      gsm.println("ATH");
    }
     else if(a=='r')
    {
      gsm.println("ATA");
    }
  }
}
    void sendMessage(){

      gsm.println("AT");
      delay(1000);
      gsm.println("AT+CMGF=1");
      delay(1000);
      gsm.println("CSCA?");
      delay(1000);
      gsm.println("AT+CMGS=\"+918281064666\"\r");
      delay(1000);
      gsm.println("hi");
      delay(1000);
      gsm.println((char)26);
      delay(1000);
      gsm.write(0x1a);
    }
    void voicecall()
    {
      gsm.println("ATD +918281064666;\r");
    }

