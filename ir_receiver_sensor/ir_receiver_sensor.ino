#include <IRremote.h>
#define BUTTON_1 0xE13DDA28
#define BUTTON_2 0xAD586662
#define BUTTON_3 0x273009C4

int IR_SENSOR = 11; // KY-022 module.
IRrecv irrecv(IR_SENSOR);
decode_results code;
int RED_LED = 2;
int GREEN_LED = 3;
int BLUE_LED = 4;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop() {
  if (irrecv.decode(&code)) {
    Serial.println(code.value, HEX);
    if (code.value == BUTTON_1) {
      digitalWrite(RED_LED, !digitalRead(RED_LED));
    }
    if (code.value == BUTTON_2) {
      digitalWrite(GREEN_LED, !digitalRead(GREEN_LED));
    }
    if (code.value == BUTTON_3) {
      digitalWrite(BLUE_LED, !digitalRead(BLUE_LED));
    }
    irrecv.resume();
  }
  delay(1000);
}
