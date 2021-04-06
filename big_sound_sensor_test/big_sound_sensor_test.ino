int MIC = 2;
int LED = 3;
int VALUE;
int STATE;

void setup() {
  Serial.begin(9600);
  pinMode(MIC, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  VALUE = digitalRead(MIC);
  if(VALUE == HIGH){
    STATE = digitalRead(LED);
    digitalWrite(LED, !STATE);
    delay(500);
    Serial.println(STATE);
  }
}
