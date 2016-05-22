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
   Serial.write(height_sensor->get_distance() + "\n");
}

void light_board::set_height_range(int min, int max) {

}

void light_board::set_z_force_range(int min, int max) {

}

int light_board::get_heighest_jump() {
    return 0;
}

void light_board::blink_board() {
    for(int i = 0; i < (sizeof(strips[0])/ sizeof(strips)); i++) {
        led_strip &strip = strips[i];
        for(int j = 0; j < strip.getNumLeds(); j++) {
            strip.set_pixel_color(j, 255, 0, 0);
        }
        strip.update();
        delay(1000);
        for(int j = 0; j < strip.getNumLeds(); j++) {
            strip.set_pixel_color(j, 0, 0, 0);
        }
        strip.update();
    }
}
















