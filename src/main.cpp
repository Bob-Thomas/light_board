#include "stdlib.h"
#include "led_strip.h"

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    auto data = due::pin_in_out(due::pins::d3);
    auto clock = due::pin_in_out(due::pins::d4);
    led_strip strip(32, data, clock);
    hwlib::cout << "step 1" << hwlib::endl;

    for (int i = 0; i < 32; i++) {
        strip.set_pixel_color(i, 0, 0, 0);
    }
    while (1) {
        for (int j = 0; j < 255; j++) {
            for (int i = 0; i < 32; i++) {
                strip.set_pixel_color(i, j, j, j);
            }
            strip.update();
            hwlib::wait_ms(10);
        }
        for (int j = 255; j > 0; j--) {
            for (int i = 0; i < 32; i++) {
                strip.set_pixel_color(i, j, j, j);
            }
            strip.update();
            hwlib::wait_ms(10);
        }
    }
}