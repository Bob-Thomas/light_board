//
// Created by endargon on 6/8/16.
//

#ifndef LIGHTBOARD_COLOR_H
#define LIGHTBOARD_COLOR_H

#include "config.h"

#ifndef byte
typedef unsigned char byte;
#endif

class Color {
    private:
        byte color[COLOR_CHANNELS];
    public:
        Color();

        Color(byte r, byte g, byte b);

        void clear();

        void set(byte r, byte g, byte b);

        byte *getColor();

    void set_brightness(int brightness);

    int return_range(int value);
};

#endif //LIGHTBOARD_COLOR_H
