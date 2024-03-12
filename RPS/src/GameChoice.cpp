#include"GameChoice.h"


GameChoice letterToGameChoice(char choice) {
    switch (choice) {
    case 'R':
    case 'r':
        return ROCK;

    case 'P':
    case 'p':
        return PAPER;

    case 'S':
    case 's':
        return SCISSORS;

    default:
        return INVALID;
    }
}

GameChoice stringToGameChoice(const std::string& choice) {
    if (choice.length() == 0 || choice.length() > 1) {
        return INVALID;
    }
    return letterToGameChoice(choice.at(0));
}

std::string getGameChoice(GameChoice choice) {
    switch (choice) {
    case ROCK:
        return "ROCK";
    case PAPER:
        return "PAPER";
    case SCISSORS:
        return "SCISSORS";
    case INVALID:
        return "Invalid Choice";
    default:
        return "";
    }       
}

char getGameChoiceLetter(GameChoice choice) {
    switch (choice) {
    case ROCK:
        return 'R';
  
    case PAPER:
        return 'P';

    case SCISSORS:
        return 'S';
    default:
        return ' ';
    }   
}

GameChoice getGameChoiceWinner(GameChoice choice) {
    switch (choice) {
    case ROCK:
        return PAPER;
        
    case PAPER:
        return SCISSORS;
    
    case SCISSORS:
        return ROCK;
    
    default:
        return INVALID;
    }   
}
