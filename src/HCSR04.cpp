//
// Created by smart on 5/22/2016.
//

#include "HCSR04.h"
#include "config.h"

HCSR04::HCSR04() : trig(due::pins::d5), echo(due::pins::d6) { }

HCSR04::HCSR04(hwlib::target::pin_in_out &trig, hwlib::target::pin_in_out &echo) : trig(trig), echo(echo) {
    trig.direction_set_output();
    echo.direction_set_input();
}

uint32_t HCSR04::get_distance() {
    trig.set(0);
    hwlib::wait_ms(2);
    trig.set(1);
    hwlib::wait_ms(10); // Added this line
    trig.set(0);
    bool received = echo.get();
    duration = hwlib::now_us();
    while(!received){received = echo.get();}
    while(received){received = echo.get();}
    duration = (hwlib::now_us() - duration)-DISTANCE_CALIBRATION;
    distance = (duration/2) / 29.1;
    return (uint32_t) distance;
}
