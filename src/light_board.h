//
// Created by smart on 5/22/2016.
//

#ifndef LIGHTBOARD_LIGHTBOARD_H
#define LIGHTBOARD_LIGHT_BOARD_H

#include <vector>
#include "HCSR04.h"
#include "ADXL335.h"
#include "led_strip.h"

struct LED_STRIP {
    LED_STRIP_PINS pins;
    uint32_t num_leds;
};

struct BOARD {
    std::vector<LED_STRIP> strips;
    ADXL_PINS accelerometer_pins;
    HCSR04 height_sensor_pins;
};

class light_board {
    private:
        BOARD board;
        std::vector<led_strip> strips;
        ADXL335* accelerometer;
        HCSR04* height_sensor;
        bool track_manuals = false;
        float jump_history[];
        uint8_t min_jump_height = 0;
        uint8_t max_jump_height = 74;
    public:
        light_board();

        light_board(BOARD pins);

        light_board(BOARD pins, bool track_manual);

        void start();

        void update();

        void set_height_range(uint8_t min, uint8_t max);

        void set_z_force_range(uint8_t min, uint8_t max);

        void blink_board(uint32_t distance);

        int get_heighest_jump();


};

#endif //LIGHTBOARD_LIGHT_BOARD_H
