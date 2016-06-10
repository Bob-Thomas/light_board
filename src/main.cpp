#include "led_strip.h"
#include "HCSR04.h"
#include "light_board.h"
#include "ADXL335.h"

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    auto data = due::pin_in_out(due::pins::d3);
    auto clock = due::pin_in_out(due::pins::d4);
    auto trig = due::pin_in_out(due::pins::d5);
    auto echo = due::pin_in_out(due::pins::d6);
    auto adxl_x = due::pin_adc(due::ad_pins::a0);
    auto adxl_y = due::pin_adc(due::ad_pins::a1);
    auto adxl_z = due::pin_adc(due::ad_pins::a2);
    led_strip strip(32, data, clock);
    HCSR04 height_sensor(trig, echo);
    ADXL335 accelerometer(adxl_x, adxl_y, adxl_z);
    light_board board(strip, height_sensor, accelerometer ,false);
    hwlib::cout << "step 1" << hwlib::endl;

    while (1) {
        board.update();
    }

}

