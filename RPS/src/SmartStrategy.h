#ifndef SMARTSTRATEGY_H
#define SMARTSTRATEGY_H

#include "GameStrategy.h"
#include "GameChoiceHistory.h"
#include <deque>
#include <string>
#include <map>

class SmartStrategy : public GameStrategy {
    private:
    GameChoiceHistory gameChoiceHistory;
    GameChoice myLastChoice;
    public:
        SmartStrategy(size_t gameChoiceHistorySize);
        virtual GameChoice makeChoice();
        virtual void onEndRound(Round round);
};



#endif