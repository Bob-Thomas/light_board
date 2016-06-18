//
// Created by endargon on 6/18/16.
//

#ifndef LIGHTBOARD_HIGHSCORE_CONTROLLER_H
#define LIGHTBOARD_HIGHSCORE_CONTROLLER_H

#include "config.h"

class highscore_controller {
private:
    int highscores[MAX_AMOUNT_OF_HIGHSCORE];

    void sort_descending(int arr[], int n);

public:
    highscore_controller();

    highscore_controller(int *predefined_scores);

    int *get_highscores();

    int highscore_index(int score);

    void add_score(int score);
};

#endif //LIGHTBOARD_HIGHSCORE_CONTROLLER_H
