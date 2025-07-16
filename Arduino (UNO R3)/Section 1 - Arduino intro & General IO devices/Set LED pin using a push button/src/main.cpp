#include <Arduino.h>

/*
  Turning ON an LED with a push-button & pull-down resistor
*/


void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
}

void loop() {
  char btnValue = digitalRead(8);
  if (btnValue)
    digitalWrite(7, HIGH);
  else
    digitalWrite(7, LOW);
}