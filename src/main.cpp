#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "C";
const char* password = "rahimc12";

// Create an AsyncWebServer object on port 1234
AsyncWebServer server(1234);

void setup() {
  // Start the Serial Monitor at 115200 baud
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  // Print ESP32 local IP address
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Serve a simple HTML page at the root ("/") endpoint
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "<h1>Hello, ESP32 Web Server!</h1>");
  });

  // Serve a simple response for another path ("/status")
  server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Server is running!");
  });

  // Start the server
  server.begin();
}

void loop() {
  // Nothing is needed here as the server is running asynchronously
}
