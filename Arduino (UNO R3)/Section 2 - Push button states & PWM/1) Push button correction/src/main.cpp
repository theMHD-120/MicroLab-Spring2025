#include <Arduino.h>

/*
  Push button correction using < delay() > instruction & Two flags
  >>> Two flags for previous & current state of push button ...
*/

#define LED_PIN 10
#define BUTTON_PIN 8

bool ledState = LOW;
bool currButton = LOW; 
bool lastPrevButton = LOW; 


void setup() {
  pinMode(BUTTON_PIN, INPUT); // set the button pin as input
  pinMode(LED_PIN, OUTPUT);   // set the LED pin as output
}

void loop() {
  currButton = digitalRead(BUTTON_PIN);
  delay(50);

  if (currButton == LOW && lastPrevButton == HIGH) {
    // Toggle the LED state
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState); // update the LED state
  }
  lastPrevButton = currButton;
}