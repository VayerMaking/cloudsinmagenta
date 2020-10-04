#include "DHT.h"
#include <FastLED.h>
#define NUM_LEDS 5
#define DATA_PIN 5
#include "ESP8266WiFi.h"  // Enables the ESP8266 to connect to the local network (via WiFi)
#include "PubSubClient.h" // Connect and publish to the MQTT broker

CRGB leds[NUM_LEDS];
// WiFi
const char* ssid = "KabelBox-XXX";                 // Your personal network SSID
const char* wifi_password = "9434763855XXXX"; // Your personal network password

// MQTT
const char* mqtt_server = "192.168.0.8";  // IP of the MQTT broker
//const char* humidity_topic = "home/livingroom/humidity";
//const char* temperature_topic = "home/livingroom/temperature";
const char* mqtt_username = "cdavid"; // MQTT username
const char* mqtt_password = "cdavid"; // MQTT password
const char* clientID = "client_livingroom"; // MQTT client ID

// Initialise the WiFi and MQTT Client objects
WiFiClient wifiClient;
// 1883 is the listener port for the Broker
PubSubClient client(mqtt_server, 1883, wifiClient);
// Custom function to connet to the MQTT broker via WiFi
void connect_MQTT(){
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Connect to the WiFi
  WiFi.begin(ssid, wifi_password);

  // Wait until the connection has been confirmed before continuing
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Debugging - Output the IP Address of the ESP8266
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Connect to MQTT Broker
  // client.connect returns a boolean value to let us know if the connection was successful.
  // If the connection is failing, make sure you are using the correct MQTT Username and Password (Setup Earlier in the Instructable)
  if (client.connect(clientID, mqtt_username, mqtt_password)) {
    Serial.println("Connected to MQTT Broker!");
  }
  else {
    Serial.println("Connection to MQTT Broker failed...");
  }

}
void setup() {
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.setBrightness(84);
  dht.begin();
}


void loop() {

  connect_MQTT();
    Serial.setTimeout(2000);



if(left == HIGH){
right_turn();
}
if(right == HIGH){
left_turn();
}
}
void right_turn(){
  right(255,255,0, 50);
  right(0,0,0, 50);
  delay(2000);
}
void left_turn(){
  left(255,255,0, 50);
  left(0,0,0, 50);
  delay(2000);
}
void stop(){
  setPixel(0, 255, 0, 0);
  showStrip();
}
void left(byte red, byte green, byte blue, int SpeedDelay) {
  int i = 4;
  while(i>-1) {
    setPixel(i, red, green, blue);
    showStrip();
    delay(SpeedDelay);
    i--;
  }
}
void right(byte red, byte green, byte blue, int SpeedDelay) {
  for(uint16_t i=0; i<NUM_LEDS; i++) {
    setPixel(i, red, green, blue);
    showStrip();
    delay(SpeedDelay);
  }
}
void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
