#include <Arduino.h>

/*
  Reading a digital value from push-button and set LED pin
*/


void setup() {
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  char btnValue = digitalRead(8);
  if (!btnValue)
    digitalWrite(7, HIGH);
  else
    digitalWrite(7, LOW);
}