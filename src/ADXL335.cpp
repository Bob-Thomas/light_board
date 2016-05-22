//
// Created by smart on 5/22/2016.
//

#include <Arduino.h>
#include "ADXL335.h"

ADXL335::ADXL335(){}

ADXL335::ADXL335(uint32_t x, uint32_t y, uint32_t z) {
    pins = {
            x,
            y,
            z
    };
    pinMode(pins.x, INPUT);
    pinMode(pins.y, INPUT);
    pinMode(pins.z, INPUT);
}
ADXL335::ADXL335(ADXL_PINS pins): pins(pins) {
    pinMode(pins.x, INPUT);
    pinMode(pins.y, INPUT);
    pinMode(pins.z, INPUT);
}

float ADXL335::get_x() {
    return calculated_value(analogRead(pins.x));
}

float ADXL335::get_y() {
    return calculated_value(analogRead(pins.y));
}

float ADXL335::get_z() {
    return calculated_value(analogRead(pins.z));
}

int ADXL335::get_raw_x() {
    return analogRead(pins.x);
}

int ADXL335::get_raw_y() {
    return analogRead(pins.y);
}

int ADXL335::get_raw_z() {
    return analogRead(pins.z);
}

float ADXL335::calculated_value(int v) {
    return ((float)v - zero_G)/scale;
}








