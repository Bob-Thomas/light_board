//
// Created by smart on 5/22/2016.
//

#ifndef LIGHTBOARD_LIGHTBOARD_H
#define LIGHTBOARD_LIGHT_BOARD_H

#include "HCSR04.h"
#include "led_strip.h"
#include "ADXL335.h"
#include "highscore_controller.h"

enum BOARD_MODES {
    IN_AIR, IDLE, RIDING
};

class light_board {
private:
    led_strip strip;
    ADXL335 accelerometer;
    HCSR04 height_sensor;
    highscore_controller highscores;
    bool jump_started = false;
    long long int jump_time;
    int current_jump_height;
    bool peak_reached = false;
    int last_jump = 0;
    uint8_t min_jump_height = MIN_JUMP_HEIGHT;
    uint8_t max_jump_height = MAX_JUMP_HEIGHT;

    void idle_lights();

    void jump_lights(int distance);

    void riding_lights();


public:
    light_board(led_strip &strip, HCSR04 &height_sensor, ADXL335 &accelerometers);

    void start();

    void update();

    void set_height_range(uint8_t min, uint8_t max);

    Color get_score_color(int score);


};

#endif //LIGHTBOARD_LIGHT_BOARD_H
