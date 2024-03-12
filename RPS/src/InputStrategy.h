#ifndef INPUTSTRATEGY_H
#define INPUTSTRATEGY_H

#include "GameStrategy.h"
class InputStrategy : public GameStrategy {
    public:
        virtual ~InputStrategy  () = default;
        virtual GameChoice makeChoice();
};

#endif