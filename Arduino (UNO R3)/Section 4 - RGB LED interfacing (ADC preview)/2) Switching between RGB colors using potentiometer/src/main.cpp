#include <Arduino.h>

/*
  Switching between Red-Green-Blue colors and their 
  Paired-combinations, using a potentiometer
*/

const int redPin = 9;
const int grnPin = 10;
const int bluPin = 11;


void setColor(int redVal, int grnVal, int bluVal) {
  digitalWrite(redPin, redVal);
  digitalWrite(grnPin, grnVal);
  digitalWrite(bluPin, bluVal);
}


void setup() {
  pinMode(A0, INPUT);
  pinMode(redPin, OUTPUT);              
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);
}

void loop() {
  float inpVal = analogRead(A0);

  if (inpVal < 128)
    setColor(255, 255, 255);
  else if (inpVal < 256)
    setColor(0, 255, 255);
  else if (inpVal < 384)
    setColor(255, 0, 255);
  else if (inpVal < 512)
    setColor(255, 255, 0);
  else if (inpVal < 640)
    setColor(0, 0, 255);
  else if (inpVal < 758)
    setColor(0, 255, 0);
  else if (inpVal < 886)
    setColor(255, 0, 0);
  else if (inpVal < 1024)
    setColor(0, 0, 0);

  delay(1000);
}