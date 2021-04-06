/*
**	Test HC-05 Bluetooth module + Arduino UNO board
**	to turn on and turn off a LED, using a
**	Bluetooth Controller app.
*/

#define RED_LED 8

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0)
  {
    char data = Serial.read(); // Reading the data received from the Bluetooth module.
    switch (data)
    {
      // Type 'l' to make light.
      case 'l':
        digitalWrite(RED_LED, HIGH);
        break; // when a is pressed on the app on your smart phone
      // Type 'd' to make darkness.
      case 'd':
        digitalWrite(RED_LED, LOW);
        break; // when d is pressed on the app on your smart phone
      default:
        break;
    }
    // Print the inputs on Serial Monitor.
    Serial.println(data);
  }
  delay(50);
}
