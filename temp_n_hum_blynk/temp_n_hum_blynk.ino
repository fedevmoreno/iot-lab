#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <SimpleTimer.h>

#define DHTTYPE DHT11
#define dht_dpin 4

DHT dht(dht_dpin, DHTTYPE);

SimpleTimer timer;

char auth[] = "SKgOfw0qW4W3yYXB_EnkTKO6k0cOYzhe";
char ssid[] = "MOVISTAR_E51E";
char pass[] = "F6N92yjxV2vGQmX6BJ4g";
float t;
float h;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(10000, sendUptime);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void sendUptime()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t);
  Serial.print("C  ");
  Serial.println();
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}
