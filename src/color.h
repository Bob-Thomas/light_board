//
// Created by endargon on 6/8/16.
//

#ifndef LIGHTBOARD_COLOR_H
#define LIGHTBOARD_COLOR_H
#pragma once

#ifndef byte
typedef unsigned char byte;
#endif

class Color {
private:
    byte color[3];
public:
    Color();

    Color(byte r, byte g, byte b);

    void clear();
    void set(byte r, byte g, byte b);
    byte* getColor();
};

#endif //LIGHTBOARD_COLOR_H
