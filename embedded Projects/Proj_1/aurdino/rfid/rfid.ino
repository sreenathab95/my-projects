void setup() {
  // put your setup code here, to run once: 
    Serial.begin(9600);

}


void loop() {
if(Serial.available()>0){   
  String a=Serial.readString();
//  Serial.println(a);
  if(a=="11004E2FE090")
  {
    Serial.println("sreenath");
  }
  else if(a=="11004E3C87E4")
  {
    Serial.println("aswathy");
  }
   else if(a=="080089359622")
  {
    Serial.println("jeevan");
  }
   else if(a=="10004B6C7641")
  {
    Serial.println("raman");
  }
   else if(a=="11004E58090E")
  {
    Serial.println("munees");
  }
}
}
