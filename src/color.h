//
// Created by endargon on 6/8/16.
//

#ifndef LIGHTBOARD_COLOR_H
#define LIGHTBOARD_COLOR_H

#include "config.h"

#ifndef byte
typedef unsigned char byte;
#endif

/**
 * Color class. A simple class to keep track of color bytes
 */
class Color {
private:
    /**
     * A byte array with the size of COLOR_CHANNELS.
    */
    byte color[COLOR_CHANNELS];

    /**
     * @return range between 0,255
     */
    int return_range(int value);
public:
    /**
     * Base constructor of the Color class.
     * Simple constructor that creates a color with the rgb values 0,0,0
     */
    Color();

    /**
     * Parametrized constructor of the Color Class.
     * Sets the rgb paramters on the byte
     * @param r red value of the color byte
     * @param g green value of the color byte
     * @param b blue value of the color byte
     */
    Color(byte r, byte g, byte b);

    /**
     * Resets the byte to 0,0,0
     */
    void clear();

    /**
     * Set the color byte.
     * Sets the rgb paramters on the byte
     * @param r red value of the color byte
     * @param g green value of the color byte
     * @param b blue value of the color byte
    */
    void set(byte r, byte g, byte b);

    /**
     * @return the color byte
     */
    byte *getColor();

    /**
     * Set the brightness of the color byte.
     * @param brightness desired brightness to be added to the color.
     */
    void set_brightness(int brightness);
};

#endif //LIGHTBOARD_COLOR_H
