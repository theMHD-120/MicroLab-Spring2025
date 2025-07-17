#include <WiFi.h>
#include <Arduino.h>
#include <HTTPClient.h>

/*
  Sending GET and POST requests to a desired server (ESP32 as a client)
  >>> A GET request in simple terms is a way to get data from a data source 
      (server) over the internet
  >>> POST request: A POST request in HTTP is used to send data to a server, 
      Typically to create or update a resource
*/

unsigned long previousMillis = 0;
unsigned long interval = 30000; // 30 seconds
const char* ssid = "Your WiFi network name";
const char* password = "Your Wi-Fi network password";


// To send a GET request
void sendGet(String url){
  HTTPClient http;
  http.begin(url);

  int httpCode = http.GET();
  
  if (httpCode > 0) {
    String payload = http.getString();
    Serial.print("Get result: ");
    Serial.println(payload);
  } else 
    Serial.printf("GET failed, error: %s\n", http.errorToString(httpCode).c_str());

  http.end(); // Free resources
}

// To send a POST request
void sendPost(String url){
  HTTPClient http;
  http.begin(url);

  http.addHeader("Content-Type", "text/plain"); // Sending raw plain text
  String rawPayload = "This is raw data sent from ESP32 sepehr";
  int httpResponseCode = http.POST(rawPayload);

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    String response = http.getString();
    Serial.print("post result:");
    Serial.println(response);

  } else {
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
  }
  
  http.end();
}

void initWiFi() {
  WiFi.mode(WIFI_AP_STA);

  int n = WiFi.scanNetworks(); // to get the number of available networks
  Serial.println("Available Networks:");
  for (int i=0; i<=n; i++){
    Serial.print(WiFi.SSID(i));
    Serial.print(" --- ");
    Serial.println(WiFi.RSSI(i));
  }

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ...");
  while (WiFi.status() != WL_CONNECTED) { // wating for connection ...
    Serial.print('.');
    delay(1000);
  }

  // When the connection is established!
  Serial.println(WiFi.localIP());
}


void setup() {
  Serial.begin(9600);
  initWiFi();
  delay(1000);

  char *URL = "https://webhook.site/dc864062-8a78-436b-983f-46905faeb702";
  sendGet(URL);
  sendPost(URL);
  /* 
    Attention: 
    The URL used has expired and needs to be changed!
    >>> See https://webhook.site
  */
}

void loop() {
  unsigned long currentMillis = millis();

  // If Wi-Fi is disconnected, it tries to reconnect ...
  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >= interval)) {
    Serial.println("Connection timed out!");
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    WiFi.reconnect();
    previousMillis = currentMillis;
  }
}