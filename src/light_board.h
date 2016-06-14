//
// Created by smart on 5/22/2016.
//

#ifndef LIGHTBOARD_LIGHTBOARD_H
#define LIGHTBOARD_LIGHT_BOARD_H

#include "HCSR04.h"
#include "led_strip.h"
#include "ADXL335.h"

class light_board {
private:
    led_strip strip;
    ADXL335 accelerometer;
    HCSR04 height_sensor;
    bool track_manuals = false;
    bool jump_started = false;
    int jump_history[255];
    long long int jump_time;
    int current_jump_height;
    bool peak_reached = false;
    uint8_t min_jump_height = 11;
    uint8_t max_jump_height = 40;
public:
    light_board();

    light_board(led_strip &strip, HCSR04 &height_sensor, ADXL335 &accelerometers, bool track_manual);

    void start();

    void update();

    void set_height_range(uint8_t min, uint8_t max);

    void set_z_force_range(uint8_t min, uint8_t max);

    void blink_board(uint32_t distance);

    int get_highest_jump();


};

#endif //LIGHTBOARD_LIGHT_BOARD_H
