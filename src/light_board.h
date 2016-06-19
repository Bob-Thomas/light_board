//
// Created by smart on 5/22/2016.
//

#ifndef LIGHTBOARD_LIGHTBOARD_H
#define LIGHTBOARD_LIGHT_BOARD_H

#include "HCSR04.h"
#include "led_strip.h"
#include "ADXL335.h"
#include "highscore_controller.h"

/** Light board class used to control the leds on the board.
 * This class gives the ability of using a led strip and a HCSR04 ultrasonic sensor.
 * Based on the ultrasonic sensor value the led strip will illuminate in different colors.
 * The lights are based on 3 modes - idle, jumping, riding
 * Idle = if the board is upside down staring into the sky this will make the leds light up in a kitt like manner
 * Jumping = If the board is in the air (jumping) it will show a red glow with brightness based on the height
 * Riding = If you're cruising around on the board it will display your latest highscore
 */
class light_board {
private:
    /**
     * Led strip class to be used on the light board
     */
    led_strip strip;

    /**
     * Accelerometer class that is currently not used
     */
    ADXL335 accelerometer;
    /**
     * The height sensor that will track the height of your jumps
     */
    HCSR04 height_sensor;
    /**
     * Highscore controller that will keep track of the highscores
     */
    highscore_controller highscores;
    /**
     * Simple flag to check if the jump has been started
     */
    bool jump_started = false;
    /**
     * Simple variable to keep track of the jump time
     */
    long long int jump_time;
    /**
     * Simple variable to keep track of the current jump height
     */
    int current_jump_height;
    /**
     * Simple flag to keep track if the peak of the jump has been reached
     */
    bool peak_reached = false;
    /**
     * Keeps track of the last jumpheight
     */
    int last_jump = 0;
    /**
     * Minimum achievable jump height
     */
    uint8_t min_jump_height = MIN_JUMP_HEIGHT;
    /**
     * Maxium achievable jump height
     */
    uint8_t max_jump_height = MAX_JUMP_HEIGHT;

    /**
     * Simple method that starts the idle light animation
     */
    void idle_lights();

    /**
     * Simple method that shows the jumping light animation based on height
     */
    void jump_lights(int distance);

    /**
     * Simple method that shows the last highscore in colored lights
     */
    void riding_lights();


public:
    /**
     * Constructor
     * Initializes the led strip and height sensor
     * @param strip an instance of a led strip
     * @param height_sensor an instance of HCSR04
     * @param accelerometer an instance of ADXL335
     */
    light_board(led_strip &strip, HCSR04 &height_sensor, ADXL335 &accelerometer);

    /**
     * Update method that does all the logic
     * Basing the lighting of the current mode (idle, riding, jumping)
     * Calculating the current height and updating and sorting highscores
     */
    void update();

    /**
     * A method that give the ability of changing the min and max jumpheight limits
     * @param min the new minimum jump height
     * @param max the new maximum jump height
     */
    void set_height_range(uint8_t min, uint8_t max);

    /**
     * Simple helper method that returns a color based on a given highscore
     * @param score value of the score you want a color based on
     * @return Color
     */
    Color get_score_color(int score);


};

#endif //LIGHTBOARD_LIGHT_BOARD_H
