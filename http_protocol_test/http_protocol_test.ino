// Board: Wemos D1 mini Pro (ESP8266)

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifiMulti;

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP("<your_network_name>", "<your_password>");
}

void loop() {
  if ((wifiMulti.run() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;

    Serial.println("[HTTP] Starting...");
    http.begin(client, "http://www.arduino.cc/asciilogo.txt");
    Serial.println("[HTTP] Get...");
    http.GET();
    String respuesta = http.getString();
    Serial.print(respuesta);
    http.end();
    delay(10000);
  }
}
