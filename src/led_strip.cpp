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
    clear();
}

void led_strip::clear() {
    for (int i = 0; i < num_leds; i++) {
        colors[i].clear();
    }
    update();
}

void led_strip::set_pixel_color(int index, Color new_color) {
    if (index < num_leds) {
        colors[index] = new_color;
    }
}

void led_strip::set_pixel_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < num_leds) {
        Color *color = &colors[index];
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
                clock.set(1);
            }
        }
    }
    clock.set(0);
    hwlib::wait_ms(1);
}

Color led_strip::getPixelColor(int index) {
    return colors[index];
}

uint32_t led_strip::getNumLeds() {
    return num_leds;
}



















