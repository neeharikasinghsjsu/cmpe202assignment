#include "Player.h"

Player::Player(const std::string& playerName, GameStrategy* strategy) 
    : name(playerName), gameStrategy(std::unique_ptr<GameStrategy>(strategy)) {}

std::string Player::getName() const {
    return name;
}

void Player::setStrategy(GameStrategy* strategy) {
    gameStrategy.reset(strategy);
}

void Player::onStartRound() {
    if (gameStrategy) {
        gameStrategy->onStartRound();
    }
}

GameChoice Player::makeChoice() {
    if (gameStrategy) {
        gameChoice = gameStrategy->makeChoice();
        return gameChoice;
    }
    return INVALID;
}

void Player::onEndRound(Round round) {
    if (gameStrategy) {
        gameStrategy->onEndRound(round);
    }
}

GameChoice Player::getChoiceMade() const {
    return gameChoice;
}

PlayerStats& Player::getPlayerStats() {
    return playerStats;
}

