#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

// Network credentials
const char* ssid = "C";
const char* password = "rahimc12";

// Web server running on port 80
AsyncWebServer server(80);

// Buzzer setup
const int buzzerPin = 23;  // GPIO pin for the buzzer
bool buzzerState = false;  // Buzzer is initially off

void setup() {
  // Start Serial Monitor for debugging
  Serial.begin(115200);

  // Initialize Wi-Fi connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize SPIFFS for file handling
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS Mount Failed");
    return;
  } else {
    Serial.println("SPIFFS Mounted Successfully");
  }

  // List all files to confirm "index.html" exists
  File root = SPIFFS.open("/");
  File file = root.openNextFile();
  while (file) {
    Serial.print("FILE: ");
    Serial.println(file.name());
    file = root.openNextFile();
  }

  // Configure the buzzer pin as output and turn it off initially
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  // Route to serve the HTML file
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });

  // Endpoint to toggle the buzzer state
  server.on("/buzz/toggle", HTTP_GET, [](AsyncWebServerRequest *request){
    buzzerState = !buzzerState; // Toggle the buzzer state
    digitalWrite(buzzerPin, buzzerState ? HIGH : LOW); // Update the buzzer
    Serial.println(buzzerState ? "Buzzer ON" : "Buzzer OFF"); // Debug message
    request->send(200, "text/plain", buzzerState ? "Buzzer ON" : "Buzzer OFF");
  });

  // Start the web server
  server.begin();
}

void loop() {
  // Empty loop since server runs asynchronously
}
