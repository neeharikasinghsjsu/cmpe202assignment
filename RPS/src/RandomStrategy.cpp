#include "RandomStrategy.h"
#include<stdlib.h>

GameChoice RandomStrategy::makeChoice() {
    int randomIndex = rand() % 3;
    return static_cast<GameChoice>(randomIndex);
};
