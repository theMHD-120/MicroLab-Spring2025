#include <Arduino.h>

/*
  Switching between RGB colors with fading
  >>> Using a potentiometer as analog input
  >>> Input range value (as digital value): 0-1023
*/

const int BLU_PIN = 9;
const int RED_PIN = 11;    
const int GRN_PIN = 10;


void setup() {
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  float RGB_val = 0;
  float inpVal = analogRead(A0);
  
  if (inpVal <= 341) {
    RGB_val = (inpVal * 255)/361;
    analogWrite(BLU_PIN, RGB_val);
    analogWrite(RED_PIN, 255 - RGB_val);
  }
  else if (inpVal <= 682) {
    inpVal -= 341;
    RGB_val = (inpVal * 255)/361;
    analogWrite(RED_PIN, RGB_val);
    analogWrite(GRN_PIN, 255 - RGB_val);
  }
  else if (inpVal <= 1023) {
    inpVal -= 682;
    RGB_val = (inpVal * 255)/361;
    analogWrite(GRN_PIN, RGB_val);
    analogWrite(BLU_PIN, 255 - RGB_val);
  }
}