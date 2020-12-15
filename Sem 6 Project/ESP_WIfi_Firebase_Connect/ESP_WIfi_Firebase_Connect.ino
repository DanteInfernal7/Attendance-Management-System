#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>

#define FIREBASE_HOST "attendance-management-sy-3b5fd.firebaseio.com"
#define FIREBASE_AUTH "jRIMungXL6P0CwkXRfvGWFJHlERWkgtUzqBsZYM3"
#define WIFI_SSID "Walawalkars 2.4Ghz"
#define WIFI_PASSWORD "jnis1h1rshjni"


void setup() {
  Serial.begin(9600);
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
  Firebase.setString("message", "hello world");
  
}
