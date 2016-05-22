#include "Arduino.h"
#include "light_board.h"

light_board board;

void setup() {
    Serial.begin(9600);
    std::vector<LED_STRIP> strips;
    strips.push_back({
                             {
                                     3,
                                     4
                             },
                             32
                     });
    BOARD board_information = {
            strips,
            {
                    A4,
                    A5
            },
            {
                    5,
                    6
            }
    };
    board = light_board(board_information);
    board.start();
}

void loop() {
    board.update();
    delay(1);
}