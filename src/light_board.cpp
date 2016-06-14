//
// Created by smart on 5/22/2016.
//

#include "light_board.h"
#include "ADXL335.h"

light_board::light_board() {

}

light_board::light_board(led_strip &strip, HCSR04 &height_sensor, ADXL335 &accelerometer, bool track_manual) :
        strip(strip),
        accelerometer(accelerometer),
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
    for (uint32_t j = 0; j < strip.getNumLeds(); j++) {
        strip.set_pixel_color(j, 10, 0, 255);
    }
    strip.update();
//    uint32_t distance = (uint32_t) height_sensor.get_distance();
//    blink_board(distance);
//    hwlib::cout << "cm: " << (int) distance << " X: " << (int) accelerometer.get_x() << " Y: " <<
//    (int) accelerometer.get_y() << " Z: " << (int) accelerometer.get_z() << hwlib::endl;
}

void light_board::set_height_range(uint8_t min, uint8_t max) {
    min_jump_height = min;
    max_jump_height = max;
}

void light_board::set_z_force_range(uint8_t min, uint8_t max) {

}

int light_board::get_highest_jump() {
    int highest = 0;
    for (int i = 0; i < int(sizeof(jump_history) / sizeof(jump_history[0])); i++) {
        if (highest < jump_history[i]) {
            highest = jump_history[i];
        }

    }
    return highest;
}

void light_board::blink_board(uint32_t distance) {
//    int impact_speed = 0;
    hwlib::cout << "cm: " << current_jump_height << hwlib::endl;
    if(!peak_reached && current_jump_height < (int)distance) {
        current_jump_height = distance;
    } else if(!peak_reached && jump_started && current_jump_height > (int)distance) {
        peak_reached = true;
        jump_time = hwlib::now_us();
        hwlib::cout << "reached peak : " << (int)distance << hwlib::endl;
    }
    if (!jump_started && (int) distance >= min_jump_height + 10) {
        hwlib::cout << "jump started" << hwlib::endl;
        jump_started = true;
    }
    if (jump_started && (int) distance <= min_jump_height + 3) {
        hwlib::cout << "jump landed" << hwlib::endl;
//        int z = accelerometer.get_z();
        jump_started = false;
        peak_reached = false;
        jump_time = (hwlib::now_us() - jump_time) - DISTANCE_CALIBRATION;
        double jump_time_in_seconds = jump_time/1000000.0;
        double velocity = (distance/jump_time_in_seconds)/100;
        double impact_force = 2*80*velocity/jump_time_in_seconds;
        hwlib::cout << "max jump height: " << current_jump_height << hwlib::endl;
        hwlib::cout << "Velocity:  " << (int)velocity << hwlib::endl;
        hwlib::cout << "impact force: " << (int)impact_force << hwlib::endl;
        hwlib::cout << jump_time << hwlib::endl;
//        impact_speed = jump_time;
        current_jump_height = 0;
    }

    if (distance > max_jump_height) {
        distance = (uint32_t) max_jump_height;
    }
    if (distance < min_jump_height) {
        distance = (uint32_t) min_jump_height;
    }
    int height_percentage = ((distance - min_jump_height) * 100) / (max_jump_height - min_jump_height);
    int color = 255 / 100 * height_percentage;
    if (distance <= min_jump_height) {
        color = 0;
    }
    for (uint32_t j = 0; j < strip.getNumLeds(); j++) {
        strip.set_pixel_color(j, color, color, color);
    }
    strip.update();
}
















