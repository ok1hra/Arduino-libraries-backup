

/// @file    NoiseRing.ino
/// @brief   Shows how to use a circular noise generator to have a continuous noise effect on a ring of LEDs.
/// @author  Zach Vorhies
///
/// This sketch is fully compatible with the FastLED web compiler. To use it do the following:
/// 1. Install Fastled: `pip install fastled`
/// 2. cd into this examples page.
/// 3. Run the FastLED web compiler at root: `fastled`
/// 4. When the compiler is done a web page will open.

#include <Arduino.h>

#include <stdio.h>

#include "fl/json.h"
#include "fl/math_macros.h"
#include "noisegen.h"
#include "fl/screenmap.h"
#include "fl/slice.h"
#include "fl/ui.h"
#include "FastLED.h"
#include "sensors/pir.h"
#include "timer.h"
#include <iostream>

#define LED_PIN 1
#define BRIGHTNESS 96
#define COLOR_ORDER GRB
#define NUM_LEDS 250
#define PIN_PIR 0

#define PIR_LATCH_MS 60000  // how long to keep the PIR sensor active after a trigger
#define PIR_RISING_TIME 1000  // how long to fade in the PIR sensor
#define PIR_FALLING_TIME 1000  // how long to fade out the PIR sensor

using namespace fl;

CRGB leds[NUM_LEDS];

Slider brightness("Brightness", 1, 0, 1);
Slider scale("Scale", 4, .1, 4, .1);
Slider timeBitshift("Time Bitshift", 5, 0, 16, 1);
Slider timescale("Time Scale", 1, .1, 10, .1);
PirAdvanced pir(PIN_PIR, PIR_LATCH_MS, PIR_RISING_TIME, PIR_FALLING_TIME);

Timer timer;
float current_brightness = 0;


void setup() {
    Serial.begin(115200);
    ScreenMap xyMap = ScreenMap::Circle(NUM_LEDS, 2.0, 2.0);
    FastLED.addLeds<WS2811, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS)
        .setCorrection(TypicalLEDStrip)
        .setScreenMap(xyMap);
    FastLED.setBrightness(brightness);
    pir.activate(millis());  // Activate the PIR sensor on startup.
}

void loop() {
    EVERY_N_SECONDS(1) {
        // printf("FPS: %d\n", FastLED.getFPS());
        std::cout << "loop" << std::endl;
    }
    uint8_t bri = pir.transition(millis());
    FastLED.setBrightness(bri * brightness.as<float>());
    uint32_t now = millis();
    double angle_offset = double(now) / 32000.0 * 2 * M_PI;
    //angle_offset = 0;
    now = (now << timeBitshift.as<int>()) * timescale.as<double>();
    // inoise8(x + ioffset,y + joffset,z);
    // go in circular formation and set the leds
    for (int i = 0; i < NUM_LEDS; i++) {
        float angle = i * 2 * M_PI / NUM_LEDS + angle_offset;
        float x = cos(angle);
        float y = sin(angle);
        x *= 0xffff * scale.as<double>();
        y *= 0xffff * scale.as<double>();
        uint16_t noise = inoise16(x, y, now);
        uint16_t noise2 = inoise16(x, y, 0xfff + now);
        uint16_t noise3 = inoise16(x, y, 0xffff + now);
        noise3 = noise3 >> 8;
        int16_t noise4 = map(noise3, 0, 255, -64, 255);
        if (noise4 < 0) {
            noise4 = 0;
        }

        leds[i] = CHSV(noise >> 8, MAX(128, noise2 >> 8), noise4);
        // std::swap(leds[i].b, leds[i].g);
    }
    FastLED.show();
}
