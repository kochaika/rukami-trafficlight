#include <FastLED.h>
#define NUMBER_LEDS 4
#define LED_PIN     5
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
const CRGB GREEN = CRGB::Green;
const CRGB RED   = CRGB::Red;
CRGB leds[NUMBER_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUMBER_LEDS);
  for(int i=0; i<NUMBER_LEDS; i++){
    leds[i] = RED;
  }
  FastLED.show();
}

void loop() {
}
