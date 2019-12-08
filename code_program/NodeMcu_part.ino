
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

#define FIREBASE_HOST "proyek3-9c81e.firebaseio.com"
#define FIREBASE_AUTH "TOuGgQ4K4zviJSKa1kJVzR8fk2c1cTyP7RdWm4vw"
#define WIFI_SSID "A1601"
#define WIFI_PASSWORD "123450989"

SoftwareSerial s(D6,D5);

  
void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  s.begin(9600);
  while (!Serial) continue;

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 
}
 
void loop() {
 StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
  if (root == JsonObject::invalid())
    return;
 
  Serial.println("JSON received and parsed");
  root.prettyPrintTo(Serial);
  delay(1000);
  
   int panjang = root["panjang"];
   Firebase.setInt("Pengukuran/panjang", panjang);
  // handle error
  if (Firebase.failed()) {
      Serial.print("panjang failed");
      Serial.println(Firebase.error());  
      return;
  }  
  delay(1000);
  
  int lebar = root["lebar"];
  Firebase.setInt("Pengukuran/lebar", lebar);
  // handle error
  if (Firebase.failed()) {
      Serial.print("lebar failed");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  int tinggi = root["tinggi"];
  Firebase.setInt("Pengukuran/tinggi", tinggi);
  // handle error
  if (Firebase.failed()) {
      Serial.print("tinggi failed");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

    int volume = root["volume"];
  Firebase.setInt("Pengukuran/volume", volume);
  // handle error
  if (Firebase.failed()) {
      Serial.print("volume failed");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

    int beratdimensi = root["beratdimensi"];
  Firebase.setInt("Pengukuran/beratdimensi", beratdimensi);
  // handle error
  if (Firebase.failed()) {
      Serial.print("beratdimensi failed");
      Serial.println(Firebase.error());  
      return;
  }
  delay(5000);
  
  Firebase.remove("Pengukuran/panjang");
  delay(1000);
  
  Firebase.remove("Pengukuran/lebar");
  delay(1000);

  Firebase.remove("Pengukuran/tinggi");
  delay(1000);
  
  Firebase.remove("Pengukuran/volume");
  delay(1000);
  
  Firebase.remove("Pengukuran/beratdimensi");
  delay(1000);
  
 
}
