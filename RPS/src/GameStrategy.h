#ifndef GAMESTRATEGY_H
#define GAMESTRATEGY_H

#include "GameChoice.h"
#include "GameData.h"

class GameStrategy {
public:
    virtual ~GameStrategy() = default;
    virtual void onStartRound() {}
    virtual GameChoice makeChoice() = 0;
    virtual void onEndRound(Round round) {}
};

#endif