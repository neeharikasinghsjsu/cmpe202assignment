#ifndef GAMECHOICE_H
#define GAMECHOICE_H

#include <string>

enum GameChoice {
    ROCK,
    PAPER,
    SCISSORS,
    INVALID
};

GameChoice letterToGameChoice(char choice);

GameChoice stringToGameChoice(const std::string& choice);

std::string getGameChoice(GameChoice choice);

char getGameChoiceLetter(GameChoice choice);

GameChoice getGameChoiceWinner(GameChoice choice);

#endif