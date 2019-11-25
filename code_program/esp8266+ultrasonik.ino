//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <NewPingESP8266.h>

// Set these to run example.
#define FIREBASE_HOST "proyek3-9c81e.firebaseio.com"
#define FIREBASE_AUTH "TOuGgQ4K4zviJSKa1kJVzR8fk2c1cTyP7RdWm4vw"
#define WIFI_SSID "Srilukman"
#define WIFI_PASSWORD "sarijadi"

#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 11 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPingESP8266 sonar1(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  
  // connect to wifi.
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

int jarakAtas = 10;

void loop() {
  int tinggi = jarakAtas - sonar1.ping_cm();
  Serial.print("Tinggi: ");
  Serial.print(tinggi);
  Serial.println(" cm");
  
  Firebase.setInt("Pengukuran/tinggi", tinggi);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
}
