#include <Arduino.h>

/*
  Toggle the LED state & modifying (correcting) its functionality using < delay() > instruction & Two flags
  >>> The best delay value is achieved through trial and error (due to the spring structure of the push-button, its value may vary)
  >>> Two flags for previous & current state of push button
  >>> This method works for push-button with both types of resistors (pull-up and pull-down); you can check
*/

#define LED_PIN 10
#define BUTTON_PIN 8

bool ledState = LOW;
bool btnCurrState = LOW; 
bool btnPrevState = LOW; 


void setup() {
  pinMode(BUTTON_PIN, INPUT); 
  pinMode(LED_PIN, OUTPUT); 
}

void loop() {
  btnCurrState = digitalRead(BUTTON_PIN);
  delay(50);

  if (btnCurrState == HIGH && btnPrevState == LOW) {
    ledState = !ledState;            // toggle the LED state
    digitalWrite(LED_PIN, ledState); // update the LED state
  }

  btnPrevState = btnCurrState;
}