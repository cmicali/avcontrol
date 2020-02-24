//
// Created by Christopher Micali on 2/24/20.
//

#include "LEDRing.h"

void LEDRing::begin() {
    pixels.begin();
}

void LEDRing::setProgress(uint8_t progress) {
    int pct = progress * this->num_pixels / 100;
    for(int i=0; i < this->num_pixels; i++) {
        int loc = (i + pixel_offset) % this->num_pixels;
        if (i<pct)
            pixels.setPixelColor(loc, pixels.Color(0, 255, 0));
        else
            pixels.setPixelColor(loc, pixels.Color(0, 0, 0));
    }
    pixels.show();
}
