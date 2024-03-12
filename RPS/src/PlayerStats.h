#ifndef PlAYERSTATS_H
#define PlAYERSTATS_H

class PlayerStats {
private:
    int wins;
    int losses;
    int ties;

public:
    PlayerStats();
    void recordWin();
    void recordLoss();
    void recordTies();
    double winPercentage() const;
    double lossPercentage() const;
    double tiePercentage() const;
    int getWins() const;
    int getTies() const;
    int totalGames() const;

};

#endif