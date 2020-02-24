//
// Created by Christopher Micali on 2/24/20.
//

#include "Knob.h"
#define ENCODER_OPTIMIZE_INTERRUPTS
#include "Encoder.h"

Encoder *encoder;

Knob::Knob(uint8_t pin1, uint8_t pin2, int32_t min, int32_t max) {
    this->encoder = new Encoder(pin1, pin2);
    this->min = min;
    this->max = max;
}

void Knob::begin() {
    Encoder* encoder = (Encoder*)this->encoder;
    encoder->write(0);
    if (invert_output) {
        min = -min;
        max = -max;
        // Swap
        min = min ^ max;
        max = min ^ max;
        min = min ^ max;
        Serial.print("Knob init: min: ");
        Serial.print(min);
        Serial.print(" max: ");
        Serial.print(max);
        Serial.println();
    }
}

int32_t Knob::read() {
    Encoder* encoder = (Encoder*)this->encoder;
    int32_t val = encoder->read();
    if (val != last_read_value) {
        if (val < min) {
            val = min;
            encoder->write(val);
        }
        if (val > max) {
            val = max;
            encoder->write(val);
        }
    }
    if (invert_output) {
        val = -val;
    }
    return val;
}

int32_t Knob::read_scaled(int32_t max) {
    return (read() * max) / this->max;
}



