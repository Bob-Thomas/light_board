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
    for(int i = 0; i < MAX_AMOUNT_OF_HIGHSCORE; i++) {
        highscores[i] = predefined_scores[i];
    }
}

void highscore_controller::sort_descending(int *arr, int n) {
    int a = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] < arr[j]) {
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}

void highscore_controller::add_score(int score) {
    for (int i = 0; i < MAX_AMOUNT_OF_HIGHSCORE; i++) {
        if (highscores[i] == 0) {
            highscores[i] = score;
            break;
        }
    }
    sort_descending(highscores, MAX_AMOUNT_OF_HIGHSCORE);
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

