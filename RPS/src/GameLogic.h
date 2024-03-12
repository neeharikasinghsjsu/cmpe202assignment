#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "GameChoice.h"
#include"Player.h"

class GameLogic {
public:
    enum RoundResult {WIN, LOSS, TIE};
    static std::string determineWinner(Player& humanPlayer, Player& computerPlayer);
    static RoundResult getRoundResult(GameChoice playerChoice, GameChoice opponentChoice);
};

#endif