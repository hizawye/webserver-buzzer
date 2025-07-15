# ESP32 Webserver Buzzer

A simple ESP32 web server application that controls a buzzer via a web interface.

## Features

- WiFi connectivity with configurable credentials
- Web-based buzzer control interface
- SPIFFS file system for serving static files
- Responsive web interface

## Setup

### 1. WiFi Configuration

This project uses environment variables for WiFi credentials to keep sensitive information secure.

1. Copy the example environment file:
   ```bash
   cp .env.example .env
   ```

2. Edit the `.env` file with your WiFi credentials:
   ```
   WIFI_SSID=YourWiFiNetworkName
   WIFI_PASSWORD=YourWiFiPassword
   ```

**Note:** The `.env` file is ignored by git to prevent accidental commits of sensitive credentials.

### 2. Build and Upload

1. Install PlatformIO if not already installed:
   ```bash
   pip install platformio
   ```

2. Build the project:
   ```bash
   pio run
   ```

3. Upload to your ESP32 device:
   ```bash
   pio run --target upload
   ```

4. Upload filesystem data (includes the web interface):
   ```bash
   pio run --target uploadfs
   ```

## Usage

1. After uploading, the ESP32 will connect to your WiFi network
2. Check the serial monitor for the assigned IP address
3. Open the IP address in your web browser
4. Use the web interface to toggle the buzzer on/off

## Hardware Requirements

- ESP32 development board
- Buzzer connected to GPIO pin 23
- Power supply for the ESP32

## Files

- `src/main.cpp` - Main application code
- `data/index.html` - Web interface
- `platformio.ini` - PlatformIO configuration
- `load_env.py` - Build script to load environment variables
- `.env.example` - Template for environment variables
- `.env` - Your WiFi credentials (create from .env.example)

## Troubleshooting

- Ensure your `.env` file exists and contains valid WiFi credentials
- Check that the buzzer is properly connected to GPIO pin 23
- Verify that your ESP32 is properly connected and powered
- Monitor the serial output for connection status and debugging information