//
// Created by smart on 5/22/2016.
//

#include "led_strip.h"


led_strip::led_strip() : num_leds(32), data(due::pin_in_out(due::pins::d3)), clock(due::pin_in_out(due::pins::d4)) {
    init();
}

led_strip::led_strip(int amount, due::pin_in_out &data, due::pin_in_out &clock) : num_leds(amount), data(data),
                                                                                  clock(clock) {
    init();
}


void led_strip::init() {
    clock.direction_set_output();
    data.direction_set_output();
    for (int i = 0; i < 32; i++) {
        colors[i].clear();
    }
}

void led_strip::clear() {
    for(int i = 0; i < num_leds; i++) {
        colors[i] = Color(0, 0, 0);
    }
    update();
}

void led_strip::set_pixel_color(int index, RGB rgb) {
    if (index < num_leds) { // Arrays are 0-indexed, thus NOT '<='
        Color *color = &colors[index];
        // See notes later regarding color order
        color->set(rgb.r, rgb.g, rgb.b);
    }
}

void led_strip::set_pixel_color(int index, Color new_color) {
    if (index < num_leds) { // Arrays are 0-indexed, thus NOT '<='
        colors[index] = new_color;
        // See notes later regarding color order
    }
}

void led_strip::set_pixel_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < num_leds) { // Arrays are 0-indexed, thus NOT '<='
        Color *color = &colors[index];
        // See notes later regarding color order
        color->set(r, g, b);
    }
}


void led_strip::update() {
    for (int i = 0; i < NUM_LEDS; i++) {
        Color color = colors[i];
        for (int j = 0; j < COLOR_CHANNELS; j++) {
            byte c = color.getColor()[j];
            for (int bitNum = CHANNEL_BIT - 1; bitNum >= 0; bitNum--) {
                clock.set(0);
                byte mask = 1 << bitNum;
                data.set(c & mask);
                // Maximum input clock frequency for the WS2801 is 25MHz,
                // so no delay is required with a 16MHz Arduino Uno.
                clock.set(1);
            }
        }
    }
    clock.set(0);
    hwlib::wait_ms(1);
}

uint32_t led_strip::getPixelColor(int index) {
    return 0;
}

uint32_t led_strip::getNumLeds() {
    return num_leds;
}



















