#pragma once
#include <vector>
#include <iostream>
#include "ScoreCard.h"
#include "Dice.h"

/**
 * Class to represent one player of the game.
 * 
 * Each player contains one scorecard. The player should
 * be the only person to interact with the score card. Any
 * changes to be made to the scorecard will be done by the 
 * player.
 * 
 * Player is also incharge of rolling his own dice. The game
 * will hand the player the dice and then the player interacts
 * with the dice.
*/
class Player {
    private:
        ScoreCard scoreCard;
    
    public:
        /**
         * Rolls the dice in player's hand.
         * 
         * @param dice the vector containing the six dice.
        */
        void rollDice(std::vector<Dice> die_vector) {
            std::vector<Dice>::iterator it = die_vector.begin();
            while (it != die_vector.end()) {
                if (!it->getHeld()) {
                    it->setValue((std::rand() % 6) + 1);
                }
                std::cout << it->getValue() << std::endl;
                it++;
            }
        }
        void holdDice(std::vector<int> dice_to_hold) {}
        void writeScoreDown(std::string category, int val) {}
        void viewScoreCard() {}
        int reportTotalScore() {return 0;}
};