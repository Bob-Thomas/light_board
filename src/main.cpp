#include "led_strip.h"
#include "HCSR04.h"
#include "light_board.h"
#include "ADXL335.h"

/*! \mainpage Light Board project page
 * This is doxygen documentation for my school project named light board.
 *
 * Light board is a project that give you the ability to keep track of the height of your jumps on your light board.
 * Based on the height of your jumps you will be rewarded with a different color and every time your break your highscore it will reward you with pretty lights
 */
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
    led_strip strip(NUM_LEDS, data, clock);
    HCSR04 height_sensor(trig, echo);
    ADXL335 accelerometer(adxl_x, adxl_y, adxl_z);
    light_board board(strip, height_sensor, accelerometer);

    while (1) {
        board.update();
    }

}

/// \todo find a nice way to use the accelerometer
/// \todo Make a reset highscore switch
/// \todo Use a display to show the user it's high scores
/// \todo Find a better casing and give the use the ability to have freedom with all the tricks on a board
