#include <iostream>
#include <time.h>
#include <vector>
#include "ScoreCard.h"
#include "Player.h"
#include "Dice.h"

int main() {
    // ScoreCard scoreCard;

    // scoreCard.updateScore("One", 3);
    // scoreCard.updateScore("Two", 6);
    // scoreCard.updateScore("Three", 9);
    // scoreCard.updateScore("Four", 12);
    // scoreCard.updateScore("Five", 15);
    // scoreCard.updateScore("Six", 18);

    // scoreCard.updateScore("Three of a Kind", 22);
    // scoreCard.updateScore("Four of a Kind", 28);
    // scoreCard.updateScore("Full House", 25);
    // scoreCard.updateScore("Small Straight", 30);
    // scoreCard.updateScore("Large Straight", 40);
    // scoreCard.updateScore("Yahtzee", 50);
    // scoreCard.updateScore("Chance", 13);

    // std::map<std::string, int> score = scoreCard.getScoreCard();
    // std::map<std::string, int>::iterator it = score.begin();
    // while (it != score.end()) {
    //     std::cout << it->first << ": " << it->second << std::endl;
    //     it++;
    // }
    std::srand(time(NULL));
    Dice dice1;
    Dice dice2;
    Dice dice3;
    Dice dice4;
    Dice dice5;
    std::vector<Dice> game_die{dice1, dice2, dice3, dice4, dice5};

    Player player1;
    player1.rollDice(game_die);

    return 0;
}