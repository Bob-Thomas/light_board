//
// Created by endargon on 6/8/16.
//

#include "color.h"

Color::Color() {
    clear();
}

Color::Color(byte r, byte g, byte b) {
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

void Color::set(byte r, byte g, byte b) {
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

void Color::clear() {
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
}

void Color::set_brightness(int brightness) {
    color[0] = return_range(color[0]+brightness);
    color[1] = return_range(color[0]+brightness);
    color[2] = return_range(color[0]+brightness);
}

int Color::return_range(int value) {
    if(value >= 255) {
        return 255;
    } else if(value <= 0) {
        return 0;
    }
    return value;
}

byte* Color::getColor() {
    return color;
}
