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
        long distance, duration;
    public:
        HCSR04();
        HCSR04(hwlib::target::pin_in_out & trig, hwlib::target::pin_in_out & echo);
        long get_distance();

};
#endif //LIGHTBOARD_HCSR04_H