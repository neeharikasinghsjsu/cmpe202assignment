#include<iostream>
#include "InputStrategy.h"

GameChoice InputStrategy::makeChoice() {
    std::string choiceEntered;
    GameChoice gameChoice = INVALID;
    while (gameChoice == INVALID) {
        std::cout << "Enter your choice (R, P, S) : ";
        std::cin >> choiceEntered;
        gameChoice = stringToGameChoice(choiceEntered);
    }
    return gameChoice;
}