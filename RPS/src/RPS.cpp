#include <iostream>
#include <sstream>
#include "GameEngine.h"
#include <time.h>
#include "Player.h"
#include "InputStrategy.h"
#include "RandomStrategy.h"
#include "SmartStrategy.h"


const int MAX_ROUNDS = 20;

int main() {

    srand(time(0));
    
    Player humanPlayer("Human", new InputStrategy());
    
    std::cout << "Choose Strategey For Computer (s for Smart, any other key for random)?" << std::endl;
    std::string choiceEntered;
    std::cin >> choiceEntered;
    
    GameStrategy * computerGameStrategy = nullptr;
    if (choiceEntered == "s") {
        std::cout <<  "Smart Strategy is chosen for Computer player" << std::endl;
        computerGameStrategy = new SmartStrategy(static_cast<size_t>(5));
    } else {
        std::cout <<  "Random Strategy is chosen for Computer player" << std::endl;
        computerGameStrategy = new RandomStrategy();
    }
    std::cout << std::endl;

    Player computerPlayer("Computer", computerGameStrategy);

    GameEngine gameEngine;
    gameEngine.gameplay(20, humanPlayer, computerPlayer);


    PlayerStats humanStats = humanPlayer.getPlayerStats();
    PlayerStats computerStats = computerPlayer.getPlayerStats();

    std::cout << "Match Stats " << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "Human Wins:   \t" << humanStats.getWins() << "\t" << humanStats.winPercentage() << "%" << std::endl;
    std::cout << "Computer Wins:\t" << computerStats.getWins() << "\t" << computerStats.winPercentage() << "%" << std::endl;
    std::cout << "Ties:         \t" << computerStats.getTies() << "\t" << humanStats.tiePercentage() << "%" << std::endl;

    
    return 0;
}