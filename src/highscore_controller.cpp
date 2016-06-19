//
// Created by endargon on 6/18/16.
//

#include "highscore_controller.h"

highscore_controller::highscore_controller() {
    for (int i = 0; i < MAX_AMOUNT_OF_HIGHSCORE; i++) {
        highscores[i] = 0;
    }
}

highscore_controller::highscore_controller(int *predefined_scores) {
    for (int i = 0; i < MAX_AMOUNT_OF_HIGHSCORE; i++) {
        highscores[i] = predefined_scores[i];
    }
    sort_descending();
}

void highscore_controller::sort_descending() {
    int a = 0;
    for (int i = 0; i < MAX_AMOUNT_OF_HIGHSCORE; ++i) {
        for (int j = i + 1; j < MAX_AMOUNT_OF_HIGHSCORE; ++j) {
            if (highscores[i] < highscores[j]) {
                a = highscores[i];
                highscores[i] = highscores[j];
                highscores[j] = a;
            }
        }
    }
}

void highscore_controller::add_score(int score) {
    for (int i = 0; i < MAX_AMOUNT_OF_HIGHSCORE; i++) {
        if (score > highscores[i]) {
            for (int j = i + 1; j > MAX_AMOUNT_OF_HIGHSCORE; j++) {
                if (j + 1 < MAX_AMOUNT_OF_HIGHSCORE) {
                    highscores[j + 1] = highscores[j];
                }
            }
            highscores[i] = score;
            break;
        }
    }
    sort_descending();
}

int *highscore_controller::get_highscores() {
    return highscores;
}

int highscore_controller::highscore_index(int score) {
    for (int i = 0; i < MAX_AMOUNT_OF_HIGHSCORE; i++) {
        if (score >= highscores[i]) {
            return i;
        }
    }
    return 0;
}

