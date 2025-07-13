#include <Arduino.h>

/*
  Set the duty cycle for an output device (LED, armature or ...) with Photocell 
  And monitor the input voltage & digital value ...
*/


void setup() {
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float digitalVal = analogRead(A0);
  float newVal = digitalVal*255/1023;
  
  Serial.print(digitalVal);
  Serial.print("-------");
  Serial.println(digitalVal*5.00/1023.00);
  analogWrite(11, newVal);
}