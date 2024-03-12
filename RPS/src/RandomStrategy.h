#ifndef RANDOMSTRATEGY_H
#define RANDOMSTRATEGY_H

#include "GameStrategy.h"
class RandomStrategy : public GameStrategy {
    public:
        virtual GameChoice makeChoice();
};

#endif