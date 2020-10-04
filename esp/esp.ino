
#include <FastLED.h>
#define NUM_LEDS 5
#define DATA_PIN 5

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.setBrightness(84);
}


void loop() {

right_turn();

left_turn();

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
