//
// Created by smart on 5/22/2016.
//

#include "HCSR04.h"

HCSR04::HCSR04() { }

HCSR04::HCSR04(uint32_t trig, uint32_t echo) {
    pins = {
            trig,
            echo
    };
    pinMode(pins.trig, OUTPUT);
    pinMode(pins.echo, INPUT);
}

HCSR04::HCSR04(HCSR04_PINS pins) : pins(pins) {
    pinMode(pins.trig, OUTPUT);
    pinMode(pins.echo, INPUT);
};

long HCSR04::get_distance() {
    digitalWrite(pins.trig, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(pins.trig, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(pins.trig, LOW);
    duration = pulseIn(pins.echo, HIGH);
    distance = (duration / 2) / 29.1;
    return distance;
}

