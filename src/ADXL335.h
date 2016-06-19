//
// Created by smart on 5/22/2016.
//

#ifndef LIGHTBOARD_ADXL335_H
#define LIGHTBOARD_ADXL335_H

#include <stdint.h>
#include <hwlib-due.hpp>

/**
 * Class for the ADXL335 accelerometer chip
 * Simple getters of the x,y and z values
 */
class ADXL335 {
private:
    //@{
    /**
     * Analog pins
     */
    due::pin_adc x, y, z;
    //@}
    /**
     * Zero G used for calibrating the sensor
     */
    const float zero_G = 506.0;
    /**
    * scale used for calibrating the sensor
     */
    const float scale = 0.0095;

    /**
     * Simple method that takes a integer(analog value) and calculates g forces with it
     * @param v value that needs to be calculated
     * @return calculated value
     */
    float calculated_value(int v);

public:
    /**
     * Base constructor for the class.
     * Automatically sets x, y, z pins on A0, A1, A2
     */
    ADXL335();

    /**
     * Parametrized constructor for the class
     * Sets the x, y, z with the given parameters
     * @param x analog pin for the x value
     * @param y analog pin for the y value
     * @param z analog pin for the z value
     */
    ADXL335(due::pin_adc &x, due::pin_adc &y, due::pin_adc &z);

    /**
     * @return calculated x value
     */
    float get_x();

    /**
     * @return calculated y value
     */
    float get_y();

    /**
     * @return calculated z value
     */
    float get_z();

    /**
     * @return raw analog value on the x pin
     */
    int get_raw_x();

    /**
    * @return raw analog value on the y pin
    */
    int get_raw_y();

    /**
     * @return raw analog value on the z pin
     */
    int get_raw_z();


};

#endif //LIGHTBOARD_ADXL335_H
