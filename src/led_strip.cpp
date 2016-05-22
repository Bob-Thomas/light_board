//
// Created by smart on 5/22/2016.
//

#include "led_strip.h"
#include "SPI.h"


led_strip::led_strip() {

}

led_strip::led_strip(int amount, uint32_t data, uint32_t clock) {
    pins = {
            data,
            clock
    };
    init(amount);
}

led_strip::led_strip(int amount, LED_STRIP_PINS pins) : pins(pins) {
    init(amount);
}

void led_strip::init(uint32_t amount_leds) {
    num_leds = ((pixels = (uint8_t *) calloc((size_t) amount_leds, 3)) != NULL) ? amount_leds : 0;
    pinMode(pins.data, OUTPUT);
    pinMode(pins.clock, OUTPUT);
}

void led_strip::set_pixel_color(int index, RGB color) {
    if (index < num_leds) { // Arrays are 0-indexed, thus NOT '<='
        uint8_t *p = &pixels[index * 3];
        // See notes later regarding color order
        *p++ = color.r;
        *p++ = color.b;
        *p++ = color.g;
    }
}

void led_strip::set_pixel_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < num_leds) { // Arrays are 0-indexed, thus NOT '<='
        uint8_t *p = &pixels[index * 3];
        // See notes later regarding color order
        *p++ = r;
        *p++ = g;
        *p++ = b;
    }
}


void led_strip::update() {
    uint16_t i, nl3 = num_leds * 3; // 3 bytes per LED
    uint8_t bit;

    for (i = 0; i < nl3; i++) {
        for (bit = 0x80; bit; bit >>= 1) {
            if (pixels[i] & bit) {
                digitalWrite(pins.data, HIGH);
            } else {
                digitalWrite(pins.data, LOW);
            }
            digitalWrite(pins.clock, HIGH);
            digitalWrite(pins.clock, LOW);

        }
    }

    delay(1); // Data is latched by holding clock pin low for 1 millisecond
}

uint32_t led_strip::getPixelColor(int index) {
    return 0;
}

led_strip::~led_strip() {
    if (pixels) free(pixels);
}

uint32_t led_strip::getNumLeds() {
    return num_leds;
}



















