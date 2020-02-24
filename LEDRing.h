//
// Created by Christopher Micali on 2/24/20.
//

#ifndef AVCONTROL_LEDRING_H
#define AVCONTROL_LEDRING_H

#include "Arduino.h"

#include <Adafruit_NeoPixel.h>

class LEDRing {
public:

    LEDRing(uint16_t num_pixels, uint16_t pin, neoPixelType type=NEO_GRB + NEO_KHZ800) : pixels(num_pixels, pin, type) {
        this->num_pixels = num_pixels;
    }

    void begin();
    void setProgress(uint8_t progress);

protected:
    Adafruit_NeoPixel pixels;
    uint8_t num_pixels;
    uint8_t pixel_offset = 18;
};


#endif //AVCONTROL_LEDRING_H
