//
// Created by smart on 5/22/2016.
//

#ifndef LIGHTBOARD_ADXL335_H
#define LIGHTBOARD_ADXL335_H

#include <stdint.h>

struct ADXL_PINS  {
    uint32_t x;
    uint32_t y;
    uint32_t z;
};
class ADXL335 {
    private:
        ADXL_PINS pins;
        const float zero_G = 512.0;
        const float scale = 102.3;
        float calculated_value(int v);

    public:
        ADXL335();
        ADXL335(ADXL_PINS pins);
        ADXL335(uint32_t x, uint32_t y, uint32_t z);
        float get_x();
        float get_y();
        float get_z();

        int get_raw_x();
        int get_raw_y();
        int get_raw_z();


};
#endif //LIGHTBOARD_ADXL335_H
