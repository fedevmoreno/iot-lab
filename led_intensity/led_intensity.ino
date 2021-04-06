// Color lights.
int red = 3;
int yellow = 5;
int green = 6;

int pot_pin = A0;
int pot_value = 0;
int light_value = 0;

void setup() {
  //It's no needed to set PWM pins.
}

void loop() {
  pot_value = analogRead(pot_pin);
  light_value = map(pot_value, 0, 1023, 0, 255);
  analogWrite(red, light_value);
  analogWrite(green, light_value);
  analogWrite(yellow, light_value);
  delay(10); 
}
