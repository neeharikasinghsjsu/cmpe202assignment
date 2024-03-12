#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include"PlayerStats.h"
#include"GameStrategy.h"
#include "GameChoice.h"
#include "GameData.h"
#include<memory>

class Player {
private:
    std::string name;
    PlayerStats playerStats;
    std::unique_ptr<GameStrategy> gameStrategy;
    GameChoice gameChoice;
public:
    Player(const std::string& name, GameStrategy* gameStrategy);
    std::string getName() const;
    void setStrategy(GameStrategy* gameStrategy);
    void onStartRound();
    GameChoice makeChoice();
    void onEndRound(Round round);
    GameChoice getChoiceMade() const;
    PlayerStats& getPlayerStats();  
};

#endif