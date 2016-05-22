//
// Created by smart on 5/22/2016.
//

#ifndef LIGHTBOARD_HCSR04_H
#define LIGHTBOARD_HCSR04_H

#include <stdint-gcc.h>
#include "Arduino.h"
struct HCSR04_PINS {
    uint32_t trig;
    uint32_t echo;
};
class HCSR04 {
    private:
        HCSR04_PINS pins;
        long distance, duration;
    public:
        HCSR04();
        HCSR04(uint32_t trig, uint32_t echo);
        HCSR04(HCSR04_PINS pins);
        long get_distance();


};
#endif //LIGHTBOARD_HCSR04_H