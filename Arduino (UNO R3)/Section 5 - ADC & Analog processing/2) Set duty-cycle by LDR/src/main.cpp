#include <Arduino.h>

/*
  Setting up the duty cycle for an output device (LED, armature or ...) 
  Using a Photocell and monitoring the input voltage & digital value
  >>> Using Photocell (in code) is like using Potentiometer (both as analog inputs)
*/


void setup() {
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float digitalVal = analogRead(A0);
  float pwmVal = digitalVal*255/1023;
  
  Serial.print(digitalVal);
  Serial.print("-------");

  // Input voltage
  Serial.println(digitalVal * 5.00 / 1023.00);

  // PWM
  analogWrite(11, pwmVal);
}