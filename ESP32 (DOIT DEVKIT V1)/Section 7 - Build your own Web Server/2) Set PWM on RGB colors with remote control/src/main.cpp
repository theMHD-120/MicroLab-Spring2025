#include <WiFi.h>
#include <Arduino.h>
#include <WebServer.h>

/*
  RGB lighting with user-controlled remote control
  >>> Remote control is done via an HTML page (on the client side)
  >>> ESP32 as a web server can be in Access Point (AP) and Station modes
*/

// Wifi SSID & Password
const char* SSID = "ESP-WebServer";
const char* Password = "123456789";

// Set PWM features
#define PWM_FREQ 5000
#define PWM_RESOLUTION 8

// Define RGB pins 
const int RED_PIN = 5;
const int GRN_PIN = 4;
const int BLU_PIN = 2;

// Initialize (create) a web server on the standard HTTP port number (80)
WebServer server(80);

// The HTML page (UI) - live submission (with sliders - not explained in slide!)
const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <title>ESP32 RGB Slider Control</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body { font-family: Arial; text-align: center; padding-top: 30px; }
      input[type=range] { width: 80%; }
      .slider-container { margin-bottom: 30px; }
      h1 { color: #333; }
    </style>
  </head>
  <body>
    <h1>ESP32 RGB LED (Slider Control)</h1>

    <div class="slider-container">
      <label for="red" style="color: red">Red</label><br>
      <input type="range" min="0" max="255" value="0" id="red">
    </div>
    <div class="slider-container">
      <label for="green" style="color: green">Green</label><br>
      <input type="range" min="0" max="255" value="0" id="grn">
    </div>
    <div class="slider-container">
      <label for="blue" style="color: blue">Blue</label><br>
      <input type="range" min="0" max="255" value="0" id="blu">
    </div>

    <script>
      const sliders = ['red', 'grn', 'blu'];
      sliders.forEach(id => {
        document.getElementById(id).addEventListener('input', sendRGB);
      });

      function sendRGB() {
        const redValue = document.getElementById('red').value;
        const grnValue = document.getElementById('grn').value;
        const bluValue = document.getElementById('blu').value;
        fetch(`/set?r=${redValue}&g=${grnValue}&b=${bluValue}`)
          .then(response => response.text())
          .then(data => console.log("Server said:", data));
      }
    </script>
  </body>
</html>
)rawliteral";

// The HTML page (UI) - submission with sumbit key (explained in slides 17&18)
// const char* htmlPage = R"rawliteral(
// <!DOCTYPE html>
// <html>
// <head>
//   <title>RGB Controller</title>
//   <style>
//     body { font-family: sans-serif; text-align: center; margin-top: 40px; }
//     input[type=number] {
//       width: 60px;
//       font-size: 16px;
//       padding: 5px;
//       margin: 5px;
//     }
//     input[type=submit] {
//       padding: 10px 20px;
//       font-size: 18px;
//       margin-top: 10px;
//     }
//   </style>
// </head>
// <body>
//   <h1>RGB LED Brightness Control</h1>
//   <form action="/set" method="GET">
//     <label style="color: red">Red:</label>
//     <input type="number" name="r" min="0" max="255" value="0"><br>
//     <label style="color: green">Green:</label>
//     <input type="number" name="g" min="0" max="255" value="0"><br>
//     <label style="color: blue">Blue:</label>
//     <input type="number" name="b" min="0" max="255" value="0"><br>
//     <input type="submit" value="Set RGB">
//   </form>
// </body>
// </html>
// )rawliteral";


// Set up PWM channels and connect to desired output pins
void setupPWM() {
  ledcSetup(0, PWM_FREQ, PWM_RESOLUTION); ledcAttachPin(RED_PIN, 0);
  ledcSetup(1, PWM_FREQ, PWM_RESOLUTION); ledcAttachPin(GRN_PIN, 1);
  ledcSetup(2, PWM_FREQ, PWM_RESOLUTION); ledcAttachPin(BLU_PIN, 2);
}

// Set brightness of RGB colors
void handleSet() {
  int redVal = server.hasArg("r") ? server.arg("r").toInt() : 0;
  int grnVal = server.hasArg("g") ? server.arg("g").toInt() : 0;
  int bluVal = server.hasArg("b") ? server.arg("b").toInt() : 0;

  // Limiting numbers entered by the user for security
  redVal = constrain(redVal, 0, 255);
  grnVal = constrain(grnVal, 0, 255);
  bluVal = constrain(bluVal, 0, 255);

  // Write values on the output chanels (RGB LED is common Adode(+))
  ledcWrite(0, 255 - redVal);
  ledcWrite(1, 255 - grnVal);
  ledcWrite(2, 255 - bluVal);

  // Submit response (refresh page after a user request)
  server.send(200, "text/html", htmlPage);
}


void setup() {
  Serial.begin(115200);
  setupPWM();

  // Set ESP32 on station mode
  // WiFi.begin(SSID, Password);
  // Serial.print("Connecting to WiFi");
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.print(".");
  // }
  // Serial.println("\nWiFi connected. IP address: ");
  // Serial.println(WiFi.localIP());

  // Set ESP32 on Access point mode
  WiFi.softAP(SSID, Password);
  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());  // default IP: 192.168.4.1

  // Server running
  server.on("/", []() {
    server.send(200, "text/html", htmlPage); // handle root
  });
  server.on("/set", handleSet);
  server.begin();
  Serial.println("WebServer started!...");
}

void loop() {
  server.handleClient(); // to handle client requests
}
