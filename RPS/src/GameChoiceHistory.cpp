#include "GameChoiceHistory.h"
#include "PatternFileManager.h"
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