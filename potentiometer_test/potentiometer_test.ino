int led_red = 3;
int pot_pin = A0;
int pot_value = 0;

void setup() { 
  pinMode(led_red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pot_value = analogRead(pot_pin);
  Serial.println(pot_value);
  digitalWrite(led_red, HIGH);
  delay(pot_value);
  digitalWrite(led_red, LOW);
  delay(pot_value);
}
