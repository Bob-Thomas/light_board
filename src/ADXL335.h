//
// Created by smart on 5/22/2016.
//

#ifndef LIGHTBOARD_ADXL335_H
#define LIGHTBOARD_ADXL335_H

#include <stdint.h>
#include <hwlib-due.hpp>


class ADXL335 {
    private:
        due::pin_adc x, y, z;
        const float zero_G = 506.0;
        const float scale = 0.0095;
        float calculated_value(int v);

    public:
        ADXL335();
        ADXL335(due::pin_adc & x, due::pin_adc & y, due::pin_adc & z);
        float get_x();
        float get_y();
        float get_z();

        int get_raw_x();
        int get_raw_y();
        int get_raw_z();


};
#endif //LIGHTBOARD_ADXL335_H
