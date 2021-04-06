#define SOIL_HUM_SENSOR A0
#define RED_LED 4
#define GREEN_LED 7

int water_limit = 80;
int need_water = 5;

int percent = 0;
int sensor_value = 0;

int convert_to_percent(int value) {
  int percent_value = 0;
  percent_value = map(value, 1023, 465, 0, 100);
  return percent_value;
}

void setup() {
  Serial.begin(9600);
  pinMode(SOIL_HUM_SENSOR, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  sensor_value = analogRead(SOIL_HUM_SENSOR);

  percent = convert_to_percent(sensor_value);

  Serial.print("\n\nAnalog Value: ");
  Serial.println(sensor_value);
  Serial.print("\nPercent: ");
  Serial.print(percent);
  Serial.print("%");

  if (percent <= need_water) {
    digitalWrite(RED_LED, HIGH);
    delay(500);
    digitalWrite(RED_LED, LOW);
    delay(500);
    digitalWrite(RED_LED, HIGH);
    delay(500);
    digitalWrite(RED_LED, LOW);
    delay(500);
    digitalWrite(RED_LED, HIGH);
    delay(500);
    digitalWrite(RED_LED, LOW);
    delay(500);
    digitalWrite(RED_LED, HIGH);
    delay(5000);
    digitalWrite(RED_LED, LOW);
  }
  if (percent >= water_limit) {
    digitalWrite(GREEN_LED, HIGH);
    delay(500);
    digitalWrite(GREEN_LED, LOW);
    delay(500);
    digitalWrite(GREEN_LED, HIGH);
    delay(500);
    digitalWrite(GREEN_LED, LOW);
    delay(500);
    digitalWrite(GREEN_LED, HIGH);
    delay(500);
    digitalWrite(GREEN_LED, LOW);
    delay(500);
    digitalWrite(GREEN_LED, HIGH);
    delay(5000);
    digitalWrite(GREEN_LED, LOW);
  }
}
