#include <Arduino.h>

/*
  Switching between Red-Green-Blue colors and their 
  Paired-combinations, like a 3-bit counter
*/

int counter = 0;
const int redPin = 9;
const int grnPin = 10;
const int bluPin = 11;


void setColor(int redVal, int grnVal, int bluVal) {
  digitalWrite(redPin, redVal);
  digitalWrite(grnPin, grnVal);
  digitalWrite(bluPin, bluVal);
}


void setup() {
  pinMode(redPin, OUTPUT);              
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);
}

void loop() {
  switch (counter)
  {
    case 0:
      setColor(255, 255, 255);
      break;
    case 1:
      setColor(0, 255, 255);
      break;
    case 2:
      setColor(255, 0, 255);
      break;
    case 3:
      setColor(255, 255, 0);
      break;
    case 4:
      setColor(0, 0, 255);
      break;
    case 5:
      setColor(0, 255, 0);
      break;
    case 6:
      setColor(255, 0, 0);
      break;
    case 7:
      setColor(0, 0, 0);
      break;
    default:
      break;
  }

  delay(1000);
  counter++;
  if(counter == 8)
    counter = 0;
}