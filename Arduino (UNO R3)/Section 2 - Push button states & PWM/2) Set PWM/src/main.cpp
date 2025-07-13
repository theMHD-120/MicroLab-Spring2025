#include <Arduino.h>

/*
  Set LED brightness using PWM (pulse-width-modulation) mode of Timer/Counters
*/

float onTime = 3.0;
float offTime = 7.0;
float dutyCycle = onTime / (onTime + offTime);


void setup() {
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  Serial.print(dutyCycle, 2);
  Serial.print("\n-------\n");
}

void loop() {
  digitalWrite(11, HIGH);
  delay(onTime);
  digitalWrite(11, LOW);
  delay(offTime);
}
