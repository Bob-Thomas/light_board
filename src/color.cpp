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

byte* Color::getColor() {
    return color;
}
