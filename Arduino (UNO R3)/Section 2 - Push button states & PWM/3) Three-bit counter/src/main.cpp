#include <Arduino.h>

/*
  A 3-bit counter that counts with each click on the push-button
  >>> Using previuos corrections of push-button (delay & flags)
*/

#define LED_RED 10
#define LED_GRN 11
#define LED_YLO 12
#define BUTTON_PIN 9

int counter = 0;
bool btnCurrState = LOW;
bool btnPrevState = LOW;


void setup() {
  pinMode(BUTTON_PIN, INPUT); // set the button pin as input
  pinMode(LED_RED, OUTPUT);   // set the Red LED pin as output
  pinMode(LED_GRN, OUTPUT);   // set the Green LED pin as output
  pinMode(LED_YLO, OUTPUT);   // set the Yello LED pin as output
}

void loop() {
  btnCurrState = digitalRead(BUTTON_PIN);
  delay(75);  

  if (btnCurrState == HIGH && btnPrevState == LOW) {
    if (!counter) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GRN, LOW);
      digitalWrite(LED_YLO, LOW);
    }
    else if (counter == 1) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GRN, LOW);
      digitalWrite(LED_YLO, LOW);
    }
    else if (counter == 2) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GRN, HIGH);
      digitalWrite(LED_YLO, LOW);
    }
    else if (counter == 3) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GRN, HIGH);
      digitalWrite(LED_YLO, LOW);
    }
    else if (counter == 4) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GRN, LOW);
      digitalWrite(LED_YLO, HIGH);
    }
    else if (counter == 5) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GRN, LOW);
      digitalWrite(LED_YLO, HIGH);
    }
    else if (counter == 6) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GRN, HIGH);
      digitalWrite(LED_YLO, HIGH);
    }
    else if (counter == 7) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GRN, HIGH);
      digitalWrite(LED_YLO, HIGH);
    }

    counter++;
    if (counter == 8)
      counter = 0;
  }

  btnPrevState = btnCurrState;
}
