//
// Created by Christopher Micali on 2/24/20.
//

#include "AVNetwork.h"

byte default_mac[] = {
        0xDE, 0xAD, 0x00, 0x00, 0x00, 0xA5
};

void AVNetwork::setup() {
    pinMode(SS, OUTPUT);
    pinMode(RST, OUTPUT);
    digitalWrite(SS, LOW);
    digitalWrite(RST, HIGH); //Reset
    delay(200);
    digitalWrite(RST, LOW);
    delay(200);
    digitalWrite(RST, HIGH);
    delay(200);              //Wait W5500
}

void AVNetwork::begin() {
    Ethernet.begin(mac, this->avr_ip);
}

AVNetwork::AVNetwork(byte mac[], IPAddress avr_ip) {
    memcpy(this->mac, mac, 6);
    this->avr_ip = avr_ip;
}

AVNetwork::AVNetwork(IPAddress avr_ip) : AVNetwork(default_mac, avr_ip) {

}
