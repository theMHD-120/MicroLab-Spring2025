#include<Arduino.h>

/*
  Set LED brightness using PWM (pulse-width-modulation) mode 
  Of Timer/Counters with the Serial input ...
*/

const int OUT_PIN = 9;
float onTime = 0;
float dutyCycle = 0;
float periodTime = 100;  // 100 milliseconds (10 Hz)


void setup() {
  pinMode(OUT_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.print("Enter ON time in microseconds (0-");
  Serial.print(periodTime);
  Serial.println("):");
}

void loop() {
  // Check for serial input
  if(Serial.available()){
    float o = Serial.parseFloat();
    while(Serial.available()) Serial.read(); // clear buffer
    
    if(o >= 0 && o <= periodTime) {  // validate input range
      onTime = o;
      dutyCycle = onTime / periodTime;
      
      Serial.print("New ON time set: ");
      Serial.print(onTime);
      Serial.print(" us, Duty cycle: ");
      Serial.println(dutyCycle * 100);
      Serial.print("Enter new ON time (0-");
      Serial.print(periodTime);
      Serial.println("):");

    } else {
      Serial.println("Invalid input! Must be between 0 and 5000");
    }
  }
  
  // Generate PWM
  if(onTime > 0) {
    digitalWrite(OUT_PIN, HIGH);
    delay(onTime);
    digitalWrite(OUT_PIN, LOW);
    delay(periodTime - onTime);
  } else {
    digitalWrite(OUT_PIN, LOW);  // if onTime is 0, keep LED off
    delay(periodTime);
  }
}

/* ------------------- Second code - simpler to use (to enter a number) ------------------- */

// #include<Arduino.h>

// const int LED_PIN = 9;
// float onTime = 0;
// float dutyCycle = 0;
// float periodTime = 2;


// void setup() {
//   pinMode(LED_PIN, OUTPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   if(Serial.available()){
//     Serial.print("Enter ON time: ");
//
//     float tempOn = Serial.readStringUntil("\n").toFloat();
//     if (tempOn != 0)
//       onTime = tempOn;
//   }

//   if (periodTime >= onTime) {
//     dutyCycle = onTime / periodTime;

//     digitalWrite(LED_PIN, HIGH);
//     delay(onTime);
//     digitalWrite(LED_PIN, LOW);
//     delay(periodTime - onTime);

//     Serial.print("The duty cycle: ");
//     Serial.println(dutyCycle);
//     Serial.println("---------");
//   }
// }