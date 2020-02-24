//
// Created by Christopher Micali on 2/24/20.
//

#ifndef AVCONTROL_AVNETWORK_H
#define AVCONTROL_AVNETWORK_H

#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

#define SS     10U    //D10 ---- SS
#define RST    11U    //D11 -----Reset

class AVNetwork {
public:
    AVNetwork(IPAddress avr_ip);
    AVNetwork(uint8_t *mac, IPAddress avr_ip);
    void setup();
    void begin();

protected:

    EthernetClient client;

    uint8_t mac[6];
    IPAddress avr_ip;

};


#endif //AVCONTROL_AVNETWORK_H
