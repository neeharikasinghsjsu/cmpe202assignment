#include "GameEngine.h"
#include "GameLogic.h"
#include <iostream>


void GameEngine::gameplay(int numRounds, Player& player1, Player& player2) {
    for (int i=1; i <= numRounds; i++) {
        std::cout << "Start Round:: " << i << std::endl;

        player1.onStartRound();
        player2.onStartRound();

        auto round = roundplay(i, player1, player2);
        roundlog(player1, player2, round);

        std::cout << "End Round:: " << i << std::endl << std::endl;

        player1.onEndRound(round);
        player2.onEndRound(round);
    }
}

Round GameEngine::roundplay(int roundNum, Player& player1, Player& player2) {
    GameChoice choice1 = player1.makeChoice();
    GameChoice choice2 = player2.makeChoice();
    return Round{roundNum, choice1, choice2};
}

void GameEngine::roundlog(Player& player1, Player& player2, Round round) {
    
    std::cout << player1.getName() << " Chose " << getGameChoice(round.choice1) << std::endl;
    std::cout << player2.getName() << " Chose " << getGameChoice(round.choice2) << std::endl;

    auto resultForPlayer1 = GameLogic::getRoundResult(round.choice1, round.choice2);
    switch (resultForPlayer1) {
        case GameLogic::WIN:
            std::cout << player1.getName() << " Wins!!!" << std::endl;
            player1.getPlayerStats().recordWin();
            player2.getPlayerStats().recordLoss();
            break;
        
        case GameLogic::LOSS:
            std::cout << player2.getName() << " Wins!!!" << std::endl;
            player1.getPlayerStats().recordLoss();
            player2.getPlayerStats().recordWin();
            break;

        case GameLogic::TIE:
            std::cout << "Its a tie!!!" << std::endl;
            player1.getPlayerStats().recordTies();
            player2.getPlayerStats().recordTies();
            break;
    }
}



