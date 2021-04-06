/**************************
Testing the MH-RD Raindrops Module.
**************************/

#define LED 4
#define RAIN_SENSOR 8

int value_rain;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(RAIN_SENSOR, INPUT);
}

void loop() {
  value_rain = digitalRead(RAIN_SENSOR);

  while (value_rain == LOW) {
    digitalWrite(LED, HIGH);
    value_rain = digitalRead(RAIN_SENSOR);
    delay(500);
  }
  digitalWrite(LED, LOW);
  delay(500);
}
