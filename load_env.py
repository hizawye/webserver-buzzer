import os
from dotenv import load_dotenv

# Load environment variables from .env file in the project root
load_dotenv(os.path.join(os.path.dirname(__file__), '.env'))

# Get WiFi credentials from environment variables
wifi_ssid = os.getenv('WIFI_SSID', 'DefaultSSID')
wifi_password = os.getenv('WIFI_PASSWORD', 'DefaultPassword')

# Set build flags to pass the credentials as preprocessor defines
Import("env")
env.Append(CPPDEFINES=[
    ("WIFI_SSID", f'\\"{wifi_ssid}\\"'),
    ("WIFI_PASSWORD", f'\\"{wifi_password}\\"')
])