//
// Created by smart on 5/22/2016.
//

#include "light_board.h"

light_board::light_board() {

}

light_board::light_board(led_strip &strip, HCSR04 &height_sensor, bool track_manual) : strip(strip),
                                                                                       height_sensor(height_sensor),
                                                                                       track_manuals(track_manual) {
    start();
}

void light_board::start() {
    for (uint32_t i = 0; i < strip.getNumLeds(); i++) {
        strip.set_pixel_color(i, 0, 0, 0);
    }
}

void light_board::update() {
    uint32_t distance = (uint32_t) height_sensor.get_distance();
    blink_board(distance);
}

void light_board::set_height_range(uint8_t min, uint8_t max) {
    min_jump_height = min;
    max_jump_height = max;
}

void light_board::set_z_force_range(uint8_t min, uint8_t max) {

}

int light_board::get_heighest_jump() {
    return 0;
}

void light_board::blink_board(uint32_t distance) {

    if (distance > max_jump_height) {
        distance = (uint32_t) max_jump_height;
    }
    if(distance < min_jump_height) {
        distance = (uint32_t) min_jump_height;
    }
    int height_percentage = float(distance) / float(max_jump_height) * 100.0;
    int color = 255 / 100 * height_percentage;
    if(distance <= min_jump_height) {
        color = 0;
    }
    for (uint32_t j = 0; j < strip.getNumLeds(); j++) {
        strip.set_pixel_color(j, color, 0, color);
    }
    strip.update();
}
















