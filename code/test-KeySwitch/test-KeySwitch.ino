#define PIN 27
int key_status;

void setup() {
  Serial.begin(9600);
  pinMode(PIN, INPUT_PULLUP);
}

void loop() {
  key_status = digitalRead(PIN);
  Serial.println(key_status);
}