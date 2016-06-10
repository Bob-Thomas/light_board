//
// Created by smart on 5/22/2016.
//

#include "ADXL335.h"

ADXL335::ADXL335() : x(due::pin_adc(due::ad_pins::a0)), y(due::pin_adc(due::ad_pins::a1)),
                     z(due::pin_adc(due::ad_pins::a2)) { }

ADXL335::ADXL335(due::pin_adc &x, due::pin_adc &y, due::pin_adc &z) : x(x), y(y), z(z) {
}

float ADXL335::get_x() {
    return calculated_value(x.get());
}

float ADXL335::get_y() {
    return calculated_value(y.get());
}

float ADXL335::get_z() {
    return calculated_value(z.get());
}

int ADXL335::get_raw_x() {
    return x.get();
}

int ADXL335::get_raw_y() {
    return y.get();
}

int ADXL335::get_raw_z() {
    return z.get();
}

float ADXL335::calculated_value(int v) {
    return ((float) v - zero_G) * scale;
}








