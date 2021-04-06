int pirSensor = 7;

int ledAlarm = 11;

void setup() {
  pinMode(pirSensor, INPUT);
  pinMode(ledAlarm, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pirSensor) == HIGH) {
    Serial.println("Movement detected!");
    digitalWrite(ledAlarm, HIGH);
    delay(2000);
    digitalWrite(ledAlarm, LOW);
  }
}
