/**********************************
*                                 *
*                                 *
* A simple project to represent   *
* traffic lights timing with data *
* taken of UK sequence.           *
*                                 *
*                                 *
**********************************/


// Traffic lights colors. And, yes! It's not yellow. It's amber.
int red = 2;
int amber = 4;
int green = 7;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(amber, OUTPUT);
  pinMode(green, OUTPUT);  
}

void loop() {
  digitalWrite(red, HIGH); // Turn on Red light.
  delay(10000); // Red light = 10sec.
  
  digitalWrite(amber, HIGH); // Turn on Amber light.
  delay(2000); // Red + Amber lights = 2sec.
  digitalWrite(red, LOW); // Turn off Red light.
  digitalWrite(amber, LOW); // Turn off Amber light.
  
  digitalWrite(green, HIGH); // Turn on Green light.
  delay(14000); // Green light = 14sec.
  digitalWrite(green, LOW); // Turn off Green light.
  
  digitalWrite(amber, HIGH); // Turn on Amber light.
  delay(3000); // Amber light = 3sec.
  digitalWrite(amber, LOW); // Turn off Amber light.  
}
