//
// Created by smart on 5/22/2016.
//

#ifndef LIGHTBOARD_HCSR04_H
#define LIGHTBOARD_HCSR04_H

#include <stdint-gcc.h>
#include <hwlib-due.hpp>

class HCSR04 {
private:
    hwlib::target::pin_in_out trig, echo;
    long duration;
    double distance;
public:
    HCSR04();

    HCSR04(hwlib::target::pin_in_out &trig, hwlib::target::pin_in_out &echo);

    uint32_t get_distance();

};

#endif //LIGHTBOARD_HCSR04_H