#include <WiFi.h>
#include <Arduino.h>
#include <WebServer.h>

/*
  Running a web server on the ESP32 board (web server initialization)
  >>> Using WebServer.h library
*/

// Wifi SSID & Password
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Initialize (create) a web server on the standard HTTP port number (80)
WebServer server(80);


void setup() {
  Serial.begin(115200);
  delay(100);

  // Set ESP32 on station mode
  // WiFi.begin(ssid, password);
  // Serial.print("Connecting to WiFi");
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.print(".");
  // }
  // Serial.println("\nWiFi connected. IP address: ");
  // Serial.println(WiFi.localIP());
  
  // Set ESP32 on Access point mode
  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());  // default IP: 192.168.4.1

  // Server running
  server.on("/", []() {
    server.send(200, "text/plain", "Hello from ESP32 using WebServer!"); // handle root
  });
  server.begin();
  Serial.println("WebServer started");
}

void loop() {
  server.handleClient(); // to handle client requests
}