#include "PlayerStats.h"

PlayerStats::PlayerStats() : wins(0), losses(0), ties(0) {}

void PlayerStats::recordWin() {
    ++wins;
};

void PlayerStats::recordLoss() {
    ++losses;
};

void PlayerStats::recordTies() {
    ++ties;
};

double PlayerStats::winPercentage() const {
    int total = totalGames();
    return total > 0 ? (static_cast<double>(wins) / total) * 100 : 0;
};

double PlayerStats::lossPercentage() const {
    int total = totalGames();
    return total > 0 ? (static_cast<double>(losses) / total) * 100 : 0;
};

double PlayerStats::tiePercentage() const {
    int total = totalGames();
    return total > 0 ? (static_cast<double>(ties) / total) * 100 : 0;
}

int PlayerStats::getWins() const {
    return wins;
}

int PlayerStats::getTies() const {
    return ties;
}

int PlayerStats::totalGames() const {
    return wins + losses + ties;
}