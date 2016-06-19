//
// Created by smart on 5/22/2016.
//

#include <math.h>
#include "light_board.h"

light_board::light_board(led_strip &strip, HCSR04 &height_sensor, ADXL335 &accelerometer) :
        strip(strip),
        accelerometer(accelerometer),
        height_sensor(height_sensor) {
    strip.clear();
}

void light_board::update() {
    uint32_t distance = (uint32_t) height_sensor.get_distance();
    if (!peak_reached && current_jump_height < (int) distance) {
        current_jump_height = distance;
    } else if (!peak_reached && jump_started && current_jump_height > (int) distance) {
        peak_reached = true;
        jump_time = hwlib::now_us();
    }
    if (!jump_started && (int) distance >= min_jump_height + 10) {
        jump_started = true;
    }
    if (jump_started && (int) distance <= min_jump_height + 3) {
        jump_time = (hwlib::now_us() - jump_time) - DISTANCE_CALIBRATION;
        if (current_jump_height < 200) {
            highscores.add_score(current_jump_height);
            last_jump = current_jump_height;
        }
        jump_started = false;
        peak_reached = false;
        current_jump_height = 0;
    }
    if (distance > 200) {
        idle_lights();
    } else {
        if (jump_started) {
            jump_lights(distance);
        } else {
            riding_lights();
        }
    }
}

void light_board::set_height_range(uint8_t min, uint8_t max) {
    min_jump_height = min;
    max_jump_height = max;
}

void light_board::idle_lights() {
    for (int i = 0; i < int(strip.getNumLeds()); i++) {
        strip.set_pixel_color(i, 0, 0, 0);
        strip.set_pixel_color(i + 3, 255, 0, 0);
        strip.set_pixel_color(i + 2, 255, 0, 0);
        strip.set_pixel_color(i + 1, 255, 0, 0);
        strip.update();
        hwlib::wait_ms(10);
    }
    for (int i = strip.getNumLeds(); i >= 3; i--) {
        if (i > 0) {
            strip.set_pixel_color(i, 0, 0, 0);
        }
        strip.set_pixel_color(i - 3, 255, 0, 0);
        strip.set_pixel_color(i - 2, 255, 0, 0);
        strip.set_pixel_color(i - 1, 255, 0, 0);
        strip.update();
        hwlib::wait_ms(10);
    }


}

void light_board::riding_lights() {
    if (last_jump == highscores.get_highscores()[0]) {
        for (uint32_t j = 0; j < strip.getNumLeds(); j++) {
            strip.set_pixel_color(j, get_score_color(last_jump));
            strip.update();
            hwlib::wait_ms(10);
        }
        for (int i = 0; i < (int) strip.getNumLeds(); i++) {
            byte red = sin(6 * i + 0) * 127 + 128;
            byte green = sin(6 * i + 2) * 127 + 128;
            byte blue = sin(6 * i + 4) * 127 + 128;
            strip.set_pixel_color(i, red, green, blue);
            strip.update();
            hwlib::wait_ms(10);
        }
        for (uint32_t j = strip.getNumLeds(); j < 0; j--) {
            strip.set_pixel_color(j, get_score_color(last_jump));
            strip.update();
            hwlib::wait_ms(10);
        }
    } else {
        for (uint32_t j = 0; j < strip.getNumLeds(); j++) {
            strip.set_pixel_color(j, get_score_color(last_jump));
        }
        strip.update();
    }
}

void light_board::jump_lights(int distance) {
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
        strip.set_pixel_color(j, color, 0, 0);
    }
    strip.update();
}

Color light_board::get_score_color(int score) {
    int highscore_position = highscores.highscore_index(score);
    switch (highscore_position) {
        case 0:
            return Color(255, 0, 0);//red
        case 1:
            return Color(255, 215, 139);//orange
        case 2:
            return Color(255, 255, 0);//yellow
        case 3:
            return Color(191, 255, 0);//lime
        case 4:
            return Color(0, 255, 0);//green
        case 5:
            return Color(64, 224, 208);//turquoise
        case 6:
            return Color(0, 139, 139);//teal
        case 7:
            return Color(0, 0, 255);//blue
        case 8:
            return Color(128, 0, 128);//purple
        case 9:
            return Color(238, 130, 238);//violet
        default:
            return Color(100, 255, 100);
    }
}


//red orange yellow lime green turquiose teal blue purple violet
