//
// Created by smart on 5/22/2016.
// This will only work for led strip with the ws801 chip
//

#ifndef LIGHTBOARD_LED_STRIP_H
#define LIGHTBOARD_LED_STRIP_H


#include <stdint-gcc.h>
#include <hwlib-due.hpp>
#include "color.h"
#include "config.h"


struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class led_strip {
private:
    uint16_t num_leds;
    due::pin_in_out data;
    due::pin_in_out clock;
    Color colors[NUM_LEDS];
public:
    led_strip(int num_leds, due::pin_in_out &data, due::pin_in_out &clock);

    void update();

    void clear();

    void set_pixel_color(int index, uint8_t r, uint8_t g, uint8_t b);

    void set_pixel_color(int index, RGB color);

    void init();

    uint32_t getPixelColor(int index);

    uint32_t getNumLeds();

    led_strip();

    void set_pixel_color(int index, Color new_color);
};

#endif //LIGHTBOARD_LED_STRIP_H
