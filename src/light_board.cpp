//
// Created by smart on 5/22/2016.
//

#include "light_board.h"

light_board::light_board() {

}

light_board::light_board(BOARD board) : board(board) {
    start();
}

light_board::light_board(BOARD board, bool track_manual) : board(board), track_manuals(track_manual) {
    start();
}

void light_board::start() {
    for(int i = 0; i < sizeof(board.strips[0])/sizeof(board.strips); i++) {
        LED_STRIP strip = board.strips[i];
        strips.push_back(led_strip(strip.num_leds, strip.pins));
    }
    accelerometer = new ADXL335(board.accelerometer_pins);
    height_sensor = new HCSR04(board.height_sensor_pins);
}

void light_board::update() {
    uint32_t distance = (uint32_t) height_sensor->get_distance();
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

    if(distance > max_jump_height) {
        distance = (uint32_t) max_jump_height;
    }
    int height_percentage = float(distance)/float(max_jump_height)*100.0;
    int color = 255/100*height_percentage;
    for(int i = 0; i < (sizeof(strips[0])/ sizeof(strips)); i++) {
        led_strip &strip = strips[i];
        for(int j = 0; j < strip.getNumLeds(); j++) {
            strip.set_pixel_color(j, color, 0, color);
        }
        strip.update();
    }
}
















