//
// Created by Christopher Micali on 2/24/20.
//

#ifndef AVCONTROL_KNOB_H
#define AVCONTROL_KNOB_H

#include "Arduino.h"

class Knob {
public:
    Knob(uint8_t pin1, uint8_t pin2, int32_t min, int32_t max);

    void begin();
    int32_t read();
    int32_t read_scaled(int32_t max);

protected:
    void *encoder;
    bool invert_output = false;
    int32_t min, max;
    int32_t last_read_value = -9999;
};


#endif //AVCONTROL_KNOB_H
