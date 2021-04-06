#include <LiquidCrystal.h>

const int sensorPin = A0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  // read the value on AnalogIn pin 0 and store it in a variable
  int sensorVal = analogRead(sensorPin);

  // send the 10-bit sensor value out the serial port
  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  // convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;

  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");

  float temperatureC = (voltage - .5) * 100;

  lcd.setCursor(0, 1);
  lcd.print(temperatureC);

  if (temperatureC <= -10.00) {
    lcd.setCursor(6, 1);
    lcd.print("F");
  } else {
    lcd.setCursor(5, 1);
    lcd.print("C");
  }

  delay(5000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temperature:");

  float temperatureF = temperatureC * (9.0 / 5.0) + 32.0;
  lcd.setCursor(0, 1);
  lcd.print(temperatureF);

  if (temperatureF >= 100.00) {
    lcd.setCursor(6, 1);
    lcd.print("F");
  } else {
    lcd.setCursor(5, 1);
    lcd.print("F");
  }

  delay(5000);
  lcd.clear();
}
