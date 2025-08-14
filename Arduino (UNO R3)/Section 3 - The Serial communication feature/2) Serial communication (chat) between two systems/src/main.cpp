#include <Arduino.h>
#include <SoftwareSerial.h>

/*
  Duplex communication (chat) between two computers (systems) using two Arduino UNO boards
  >>> One Arduino as the transmitter and another Arduino as the receiver (and vice versa)
  >>> Serial.h: The main serial interface for communication between Arduino UNO and our systems
  >>> SoftwareSerial.h: The virtual serial interface for communication between two Arduino boards
  >>> Note: To connect two Arduino boards and to exchange data between them, they must have a common ground

*/

// SoftwareSerial pins (RX, TX)
#define SOFT_RX 10  // connect to other Arduino's TX
#define SOFT_TX 11  // connect to other Arduino's RX
SoftwareSerial chatSerial(SOFT_RX, SOFT_TX); // for Arduino-to-Arduino communication


void setup() {
  Serial.begin(9600);     // for USB communication with PC
  chatSerial.begin(9600);  // for Arduino-to-Arduino communication
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Chat system ready! Type messages below.");
}

void loop() {
  
  // Check for incoming messages from other Arduino
  if (chatSerial.available()) {
    String incoming = chatSerial.readStringUntil('\n');
    incoming.trim();
    
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Received: ");
    Serial.println(incoming);
    digitalWrite(LED_BUILTIN, LOW);
  }

  // Check for user input from Serial Monitor
  if (Serial.available()) {
    String outgoing = Serial.readStringUntil('\n');
    outgoing.trim();
    
    if (outgoing.length() > 0) {
      Serial.print("Sent: ");
      Serial.println(outgoing);
      chatSerial.println(outgoing); // send to other Arduino
    }
  }
}