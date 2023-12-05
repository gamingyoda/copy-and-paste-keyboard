#include "Keyboard.h"
#define copy_PIN 26 
#define paste_PIN 27

int copy_lastState = HIGH;
int copy_currentState;
int paste_lastState = HIGH;
int paste_currentState;

void copy(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  Keyboard.releaseAll();
  delay(100);
}

void paste(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('v');
  Keyboard.releaseAll();
  delay(100);
}
void setup() {
  Keyboard.begin();
  pinMode(copy_PIN, INPUT_PULLUP);
  pinMode(paste_PIN, INPUT_PULLUP);
}

void loop() {
  copy_currentState = digitalRead(copy_PIN);
  paste_currentState = digitalRead(paste_PIN);
  if(copy_lastState == 0 && copy_currentState == 1) {
    delay(50);
    if(digitalRead(copy_PIN) == 1) copy();
  } 
  if(paste_lastState == 0 && paste_currentState == 1) {
    delay(50);
    if(digitalRead(paste_PIN) == 1) paste();
  }
  copy_lastState = copy_currentState;
  paste_lastState = paste_currentState;
}