#include <FastLED.h>
#include "TimerObject.h"
#define NUMBER_LEDS 4
#define LED_PIN     5
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
const CRGB GREEN = CRGB::Green;
const CRGB RED   = CRGB::Red;
CRGB leds[NUMBER_LEDS];
#define CHANGE_TIME 2
TimerObject *change_timer;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUMBER_LEDS);
  for(int i=0; i<NUMBER_LEDS; i++){
    leds[i] = RED;
  }
  leds[0] = leds[2] = GREEN;
  FastLED.show();
  change_timer = new TimerObject(CHANGE_TIME*1000);
  change_timer->setOnTimer(flip);
  change_timer->Start();
  pinMode(2, INPUT_PULLUP);
}

void flip(){
    for(int i=0; i<NUMBER_LEDS; i++)
        leds[i] = leds[i]==GREEN ? RED : GREEN;
    FastLED.show();
}

void loop() {
   change_timer->Update();
  if(digitalRead(2) == LOW){
    change_timer->Start();
    flip();
    delay(300);
  }
}



