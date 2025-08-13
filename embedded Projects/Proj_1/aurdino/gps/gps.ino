#include <SoftwareSerial.h>
#include <TinyGPS.h>
long lat,lon;
SoftwareSerial gpsSerial(3,4);
TinyGPS gps;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gpsSerial.begin(4800);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(gpsSerial.available()){
    if(gps.encode(gpsSerial.read())){
      gps.get_position(&lat,&lon);
      Serial.println("position:   ");
      Serial.println("lat:   ");
      Serial.println(lat);
      Serial.println("  ");
      Serial.println("lon:  ");
      Serial.println(lon);
    }
  }

}
