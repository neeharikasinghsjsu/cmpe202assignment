#ifndef SMARTSTRATEGY_H
#define SMARTSTRATEGY_H

#include "GameStrategy.h"
#include <deque>
#include <string>
#include <map>

static const std::string FREQ_FILE_NAME = "data/freq.txt";

class GameChoiceHistory {
private:
    std::deque<char> gameChoicePattern;
    std::map<std::string, int> patternHistory;
    size_t maxHistorySize;

public:
    GameChoiceHistory(size_t maxHistorySize);
    ~GameChoiceHistory();

    void append(char c);
    void incrementCurrentPatternsFrequency();
    std::string toString() const;
    int getPatternFrequency(const std::string& pattern) const;
    int getMaxChoiceHistorySize() const;
};

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