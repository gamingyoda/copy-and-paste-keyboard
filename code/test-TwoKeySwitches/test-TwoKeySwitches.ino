#define PIN1 26 
#define PIN2 27

int key_status1;
int key_status2;

void setup() {
  Serial.begin(9600);
  pinMode(PIN1, INPUT_PULLUP);
  pinMode(PIN2, INPUT_PULLUP);
}

void loop() {
  key_status1 = digitalRead(PIN1);
  key_status2 = digitalRead(PIN2);
  if (key_status1 == LOW) Serial.println("KeyNumber1 pressed");
  if (key_status2 == LOW) Serial.println("KeyNumber2 pressed");
}