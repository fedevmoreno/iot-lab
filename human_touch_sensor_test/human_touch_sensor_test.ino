int VALUE = 8;
int LED = 12;

void setup() {
  pinMode(VALUE, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  if(digitalRead(VALUE) == HIGH){
    digitalWrite(LED, HIGH);
  }
  delay(500);
  digitalWrite(LED, LOW);
}
