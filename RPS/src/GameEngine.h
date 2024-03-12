#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "GameStrategy.h"
#include "GameData.h"

class GameEngine
{
private:
    Round roundplay(int roundNum, Player& player1, Player& player2);
    void roundlog(Player& player1, Player& player2, Round round); 

public:
    void gameplay(int numRounds, Player& player1, Player& player2);
    
};


#endif