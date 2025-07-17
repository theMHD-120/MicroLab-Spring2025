#include <Arduino.h>

/*
  Adjusting LED brightness using Pulse-Width-Modulation (PWM as a timer/counter mode)
*/

float onTime = 3.0;
float offTime = 7.0;
float dutyCycle = onTime / (onTime + offTime);


void setup() {
  pinMode(11, OUTPUT);
  Serial.begin(9600);

  // Duty cycle with a precision of 2 digits after the decimal point
  Serial.println(dutyCycle, 2);
  Serial.println("----------");
}

void loop() {
  digitalWrite(11, HIGH);
  delay(onTime);
  digitalWrite(11, LOW);
  delay(offTime);
}
