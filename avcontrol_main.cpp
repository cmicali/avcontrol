#include <Arduino.h>

#include "AVNetwork.h"
#include "Knob.h"
#include "LEDRing.h"
#include "Util.h"

#define AVR_IP      10,5,0,1

Knob knob(2, 0, 0, 100);
LEDRing ledRing(24, 5);
AVNetwork network(IPAddress(AVR_IP));

void setup() {
    network.setup();
    Serial.begin(9600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }
    delay(1000);
    Serial.println("AVControl starting...");
    network.begin();
    knob.begin();
    ledRing.begin();
    Serial.println("AVControl started");
}

long last_pos  = -99999;

void loop() {
    long pos = knob.read_scaled(100);
    if (pos != last_pos) {
        last_pos = pos;
        ledRing.setProgress(pos);
        Serial.println(pos);
    }

}