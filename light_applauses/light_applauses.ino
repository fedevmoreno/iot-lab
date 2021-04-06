/*
  Using the Big Sound Sensor (KY-038) and an Arduino UNO board, this sketch make possible
  to do 2 applauses to TURN ON the lamp (RELAY) and 3 applauses to TURN OFF the lamp.
*/

const int MIC = 7;
bool CLAP_DETECTED = false;
bool FIRST_CLAP = false;
bool SECOND_CLAP = false;
bool THIRD_CLAP = false;

const int LED = 13;

const int RELAY = 2;

bool STATE = false;

unsigned long TEM;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(MIC, INPUT);
  //Serial.begin(9600);
}

void loop() {
  CLAP_DETECTED = digitalRead(MIC);

  if ((CLAP_DETECTED == true) && (FIRST_CLAP == false) && (SECOND_CLAP == false) && (THIRD_CLAP == false)) {
    FIRST_CLAP = true;
    //Serial.println("Primera palmada!");
    TEM = millis();
    delay (200);
  }

  else if ((CLAP_DETECTED == true) && (FIRST_CLAP == true) && (SECOND_CLAP == false) && (THIRD_CLAP == false) ) {
    SECOND_CLAP = true;
    //Serial.println("Segunda palmada!");
    delay (200);
  }

  else if ((CLAP_DETECTED == true) && (FIRST_CLAP == true) && (SECOND_CLAP == true) && (THIRD_CLAP == false) ) {
    THIRD_CLAP = true;
    //Serial.println("Tercera palmada!");
    delay (200);
  }

  if ((FIRST_CLAP == true) && (SECOND_CLAP == true) && (THIRD_CLAP == false) && (STATE == false)) {
    STATE = !STATE;
    digitalWrite(LED, HIGH);
    digitalWrite(RELAY, HIGH);
    delay(500);
    //Serial.println("Reset");
    FIRST_CLAP = false;
    SECOND_CLAP = false;
    THIRD_CLAP = false;
  }

  if ((FIRST_CLAP == true) && (SECOND_CLAP == true) && (THIRD_CLAP == true) && (STATE == true)) {
    STATE = !STATE;
    digitalWrite(LED, LOW);
    digitalWrite(RELAY, LOW);
    delay(500);
    //Serial.println("Reset");
    FIRST_CLAP = false;
    SECOND_CLAP = false;
    THIRD_CLAP = false;
  }

  if (((millis() - TEM) >= 500) && (FIRST_CLAP == true) && (SECOND_CLAP == true || THIRD_CLAP == false)) {
    //Serial.println("Reset Time");
    //Serial.println((millis() - TEM));
    FIRST_CLAP = false;
    SECOND_CLAP = false;
    THIRD_CLAP = false;
  }
}
