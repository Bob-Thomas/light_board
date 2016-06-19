//
// Created by smart on 5/22/2016.
// This will only work for led strip with the ws801 chip
//

/**
 * Credits to https://github.com/adafruit/Adafruit-WS2801-Library
 * for showing me how to start on this
 */
#ifndef LIGHTBOARD_LED_STRIP_H
#define LIGHTBOARD_LED_STRIP_H


#include <stdint-gcc.h>
#include <hwlib-due.hpp>
#include "color.h"
#include "config.h"

/**
 * Led strip class
 * This class will only work with a led strip based on ws801 chip with data and clock separated
 */
class led_strip {

private:
    /**
     * Number of leds used
     */
    uint16_t num_leds;
    /**
     * Pin that corresponds to the data pin
     */
    due::pin_in_out data;
    /**
     * Pin that corresponds to the clock pin
     */
    due::pin_in_out clock;
    /**
     * Array of Colors with the size of the number of leds
     */
    Color colors[NUM_LEDS];
public:
    /**
     * Base constructor that puts the number of leds on 32 and data and clock pin on 3, 4
     */
    led_strip();

    /**
     * Constructor for the led strip.
     * @param num_leds amount of leds on the strip
     * @param data the pin that corresponds to the data pin on the led strip
     * @param clock the pin that corresponds to the clock pin on the led strip
     */
    led_strip(int num_leds, due::pin_in_out &data, due::pin_in_out &clock);

    /**
     * Method that updates the led strip with the current set colors
     */
    void update();

    /**
     * Wipes out out the led strip putting everything on rgb(0, 0, 0)
     */
    void clear();

    /**
     * Sets the rgb value of a pixel corresponding to the index of the number of leds
     * @param index position of led on the strip
     * @param r red color value
     * @param g green color value
     * @param b blue color value
     */
    void set_pixel_color(int index, uint8_t r, uint8_t g, uint8_t b);

    /**
     * Sets the color of a pixel corresponding to the index of the number of leds
     * @param index position of led on the strip
     * @param new_color a new colpr
     */
    void set_pixel_color(int index, Color new_color);


    /**
     * Sets the pins of the to the needed output or input mode
     * Clears the led strip with 0,0,0
     */
    void init();

    /**
     * @return the color of the pixel corresponding to the index
     */
    Color getPixelColor(int index);

    /**
     * @return the number of leds used
     */
    uint32_t getNumLeds();


};

#endif //LIGHTBOARD_LED_STRIP_H
