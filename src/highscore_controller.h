//
// Created by endargon on 6/18/16.
//

#ifndef LIGHTBOARD_HIGHSCORE_CONTROLLER_H
#define LIGHTBOARD_HIGHSCORE_CONTROLLER_H

#include "config.h"

/**
 * Class that can keep track and sort highscores
 */
class highscore_controller {
private:
    /**
     * Array that holds the highscores
     */
    int highscores[MAX_AMOUNT_OF_HIGHSCORE];

    /**
     * Method that sorts the highscore in a descending order
     */
    void sort_descending();

public:
    /**
     * Base constructor for the highscore controller sets the highscores on 0
     */
    highscore_controller();

    /**
     * Parametrised constructor that gives you the ability to set predefined highscores
     * @param predefined_scores an array with predefined highscores
     */
    highscore_controller(int *predefined_scores);

    /**
     * @return the current highscore array
     */
    int *get_highscores();

    /**
     * returns of the highscore closest to the parameter score
     * @param score a given score
     * @return the index
     */
    int highscore_index(int score);

    /**
     * Adds a new score to the highscore list and sorts
     * @param score new score that needs to be added
     */
    void add_score(int score);
};

#endif //LIGHTBOARD_HIGHSCORE_CONTROLLER_H
