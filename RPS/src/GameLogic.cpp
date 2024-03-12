#include "GameLogic.h"

GameLogic::RoundResult GameLogic::getRoundResult(GameChoice playerChoice, GameChoice opponentChoice) {
    if (playerChoice == opponentChoice) {
        return GameLogic::TIE;
    }

    if ((playerChoice == ROCK && opponentChoice == SCISSORS) ||
                (playerChoice == PAPER && opponentChoice == ROCK) ||
                (playerChoice == SCISSORS && opponentChoice == PAPER)) {
                
        return GameLogic::WIN;
    }

    return GameLogic::LOSS;
}





