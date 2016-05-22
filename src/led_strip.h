//
// Created by smart on 5/22/2016.
// This will only work for led strip with the ws801 chip
//

#ifndef LIGHTBOARD_LED_STRIP_H
#define LIGHTBOARD_LED_STRIP_H

#include <stdint.h>
#include <chip.h>
#include <sched.h>

struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct LED_STRIP_PINS {
    uint32_t data;
    uint32_t clock;
};

class led_strip {
    private:
        uint32_t clock_pin;
        uint32_t data_pin;
        uint16_t num_leds;
        uint8_t *pixels;
        LED_STRIP_PINS pins;
    public:
        ~led_strip();
        led_strip(int num_leds, LED_STRIP_PINS pins);
        led_strip(int num_leds, uint32_t data_pin, uint32_t clock_pin);
        void update();
        void set_pixel_color(int index, uint8_t r, uint8_t g, uint8_t b);
        void set_pixel_color(int index, RGB color);
        void init(uint32_t amount_leds);
        uint32_t getPixelColor(int index);
        uint32_t getNumLeds();

        led_strip();
};
#endif //LIGHTBOARD_LED_STRIP_H
