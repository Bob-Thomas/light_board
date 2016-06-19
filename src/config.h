//
// Created by smart on 6/8/2016.
//

#ifndef LIGHTBOARD_CONFIG_H
#define LIGHTBOARD_CONFIG_H
/**
 * Config file with all the constants.
 */
#define NUM_LEDS 30 /* Number of leds being used */
#define CHANNEL_BIT 8 /* Chanel bit for led strip */
#define COLOR_CHANNELS 3 /* Color channels RGB */
#define DISTANCE_CALIBRATION 400 /* Distance calibration now_us was 400ms offset */
#define MAX_JUMP_HEIGHT 114 /* Max jumpheight 144 = current jump record on a skateboard */
#define MIN_JUMP_HEIGHT 11 /* Minimum height that begins to register as a jump */
#define MAX_AMOUNT_OF_HIGHSCORE 10 /* Max amount of highscores kept */
#endif //LIGHTBOARD_CONFIG_H
