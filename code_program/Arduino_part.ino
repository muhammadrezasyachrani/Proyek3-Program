#include <NewPing.h>

#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(10,11);

NewPing sonar1(3, 2, 11);
NewPing sonar2(5, 4, 17);
NewPing sonar3(7, 6, 17);

int jarakAtas = 11;
int jarakSamping = 17;
int jarakDepan = 17;

int tinggi,panjang,lebar,volume,beratdimensi;
 
void setup() {
s.begin(9600);
Serial.begin(9600);
Serial.print(s);
}
 
void loop() {
 StaticJsonBuffer<1000> jsonBuffer;
 JsonObject& root = jsonBuffer.createObject();
 delay(1000);
 
 panjang = jarakDepan - sonar2.ping_cm();
  root["panjang"] = panjang;
 delay(1000);
  lebar = jarakSamping - sonar3.ping_cm();
  root["lebar"] = lebar;
 delay(1000);
 tinggi = jarakAtas - sonar1.ping_cm();
  root["tinggi"] = tinggi;
 delay(1000);
 volume = panjang * lebar * tinggi;
  root["volume"] = volume;
 delay(1000);
 beratdimensi = volume / 4;
  root["beratdimensi"] = beratdimensi;
 delay(1000);
  root.printTo(s);
 delay(1000);
}
