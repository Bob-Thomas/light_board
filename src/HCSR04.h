//
// Created by smart on 5/22/2016.
//

/**
 * Credits to http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
 * For showing me a easy example I could revamp to work with hwlib
 */
#ifndef LIGHTBOARD_HCSR04_H
#define LIGHTBOARD_HCSR04_H

#include <stdint-gcc.h>
#include <hwlib-due.hpp>

/**
 * Class for the HCSR04 Ultrasonic sensor
 */
class HCSR04 {
private:
    //@{
    /**
     * Digital IO pins for trig and echo
     */
    hwlib::target::pin_in_out trig, echo;
    //@}

public:

    /**
     * Base constructor that puts the pins on 5, 6 for a due
     */
    HCSR04();

    /**
     * Parametrized constructor that sets the pins to the given pins .
     * @param trig the pin that will be set as the trig pin
     * @param echo the pin that will be set as the echo pin
     */
    HCSR04(hwlib::target::pin_in_out &trig, hwlib::target::pin_in_out &echo);

    /**
     * @return current distance on the sensor
     */
    uint32_t get_distance();

};

#endif //LIGHTBOARD_HCSR04_H