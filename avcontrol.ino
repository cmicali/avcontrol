#include <Arduino.h>
#include <Encoder.h>
#include <Adafruit_NeoPixel.h>

#define PIN        5
#define NUMPIXELS 24

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Encoder myEnc(2, 0);

void setup() {
    Serial.begin(9600);
    Serial.println("Basic Encoder Test:");
    pixels.begin();
}

long oldPosition  = 0;

void loop() {
    long newPosition = myEnc.read();
    if (newPosition != oldPosition) {
        oldPosition = newPosition;
        Serial.println(newPosition);
    }
    int pct = -newPosition % 100;
    pct = pct * NUMPIXELS / 100;
    for(int i=0; i<NUMPIXELS; i++) {
        if (i<pct)
            pixels.setPixelColor(i, pixels.Color(0, 255, 0));
        else
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        pixels.show();
    }

}