#include "SmartStrategy.h"
#include "PatternFileManager.h"
#include "GameChoice.h"
#include <iostream>

GameChoiceHistory::GameChoiceHistory(size_t maxHistorySize) : maxHistorySize(maxHistorySize) {
    patternHistory = PatternFileManager::loadPatternsFromFile(
        FREQ_FILE_NAME);
}

GameChoiceHistory::~GameChoiceHistory() {
    PatternFileManager::savePatternsToFile(patternHistory, FREQ_FILE_NAME);
}


void GameChoiceHistory::append(char c) {
    if(gameChoicePattern.size() == maxHistorySize) {
        gameChoicePattern.pop_front();
    }
    gameChoicePattern.push_back(c);

    std::cout << "APPENDED: " << c << std::endl;
    std::cout << "HISTORY: " << toString() << std::endl;
}

void GameChoiceHistory::incrementCurrentPatternsFrequency() {
    if(gameChoicePattern.size() == maxHistorySize) {
        std::string currentPattern = toString();
        patternHistory[currentPattern]++;

        std::cout << "UPDATED FREQUENCY: " << toString() << ":" 
            << patternHistory[currentPattern]++ << std::endl;
    }
}

std::string GameChoiceHistory::toString() const {
    return std::string(gameChoicePattern.begin(), gameChoicePattern.end());
}

int GameChoiceHistory::getPatternFrequency(const std::string& pattern) const {
    auto it = patternHistory.find(pattern);
    if (it != patternHistory.end()) {
        return it->second;
    }
    return 0; // Pattern not found
}

int GameChoiceHistory::getMaxChoiceHistorySize() const {
    return maxHistorySize;
}


SmartStrategy::SmartStrategy(size_t gameChoiceHistorySize) : gameChoiceHistory(gameChoiceHistorySize) {}

GameChoice SmartStrategy::makeChoice() {
    std::string currentPattern = gameChoiceHistory.toString();

    // make random choice as default
    int randomIndex = rand() % 3;
    GameChoice choice = static_cast<GameChoice>(randomIndex);

    if (currentPattern.length() >= gameChoiceHistory.getMaxChoiceHistorySize() - 1) {
        std::string lessOnePattern = currentPattern.substr(currentPattern.length() - gameChoiceHistory.getMaxChoiceHistorySize() + 1);
        int maxFreq = 0;
        for (char c : {'R', 'P', 'S'}) {
            std::string option = lessOnePattern + c;
            int freq = gameChoiceHistory.getPatternFrequency(option);
            std::cout << "CHECKED FREQUENCY: " << lessOnePattern << "(" << c << "):" 
                << freq << std::endl;
            if (freq > maxFreq) {
                choice = letterToGameChoice(c);
                maxFreq = freq;
            }
        }
    } else {
        std::cout << "Insufficient history to predict." << std::endl;
        std::cout << "Computer chose randomly." << std::endl;
    }

    myLastChoice = getGameChoiceWinner(choice); 
    return myLastChoice;
}

void SmartStrategy::onEndRound(Round round) {

    std::cout << std::endl;
    std::cout << "Smart Strategy History Log" << std::endl;

    GameChoice opponentChoice = round.choice1 == myLastChoice
        ? round.choice2 // doesn't matter if both choices are same
        : round.choice1;
    
    gameChoiceHistory.append(getGameChoiceLetter(opponentChoice));
    gameChoiceHistory.incrementCurrentPatternsFrequency();
    gameChoiceHistory.append(getGameChoiceLetter(myLastChoice));

    std::cout << std::endl;
    
}
