#include <SoftwareSerial.h>
void sendMessage();
void RecieveMessage();
void DialCall();
void attend();
SoftwareSerial gsm(9,10);
void setup() {
  // put your setup code here, to run once:
  gsm.begin(9600);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  if(Serial.available()>0)
  {
    gsm.write(Serial.read());
  }
  if(gsm.available()>0)
  {
    Serial.write(gsm.read());
    if(Serial.readString()=="RING")
    {
      gsm.println("ATA");
      delay(100);
    }
  }
  if(Serial.available()>0)
  { 
    char a=Serial.read();
    Serial.println(a);
    if(a=='s')
    {
      sendMessage();
      
    }
    if(a=='d')
   {
     DialCall();
    }
    if(a=='r')
    {
      RecieveMessage();
    }
    if(a=='a')
    {
      attend();
    }
    if(a=='c')
    {
      cutcall();
    }
  }
}
    void sendMessage(){

      gsm.println("AT");
      delay(1000);
      gsm.println("AT+CMGF=1");
      delay(1000);
      gsm.println("AT+CMGS=\"+918281064666");
      delay(1000);
      gsm.println("itheppadi mwonuse");
      delay(1000);
      gsm.println((char)26);
      delay(1000);
      gsm.write(0x1a);
    }
    void DialCall()
    {
      
      gsm.println("ATD +918281064666;\r");
      delay(100);
    }
    void RecieveMessage(){
       gsm.println("AT+CMGF=1\r");
        gsm.println("AT+CNMI=2,2,0,0,0\r");
        delay(100); 
    }
void attend()
{
  gsm.println("ATA");
  delay(100);
}
void cutcall()
{
  gsm.println("ATH");
}





