#pragma once
#include <iostream>
#include <map>

/**
 * Class to represent the scorecard in Yahtzee.
 * 
 * Functions to update score card all held as private. Score card
 * should only be manipulated by the updateScore function and the
 * class attributes holding the scores should only be accessed by
 * the update functions themselves, which are called each time the
 * board is requested.
*/
class ScoreCard {
    private:
        /**
         * Class attribute declaration.
        */
        std::map<std::string, int> upper_score_card;
        std::map<std::string, int> lower_score_card;
        int upper_score = 0;
        int lower_score = 0;
        int upper_bonus = 0;
        int yahtzee_bonus = 0;
        int total_score = 0;

        /**
         * Updates the score of the upper section of scorecard.
         * 
         * Yahtzee score card is split into two halves. Top half
         * contains multiples of 1-6 and its total is used to 
         * calc an upper bonus.
        */
        void updateUpperScore() {
            std::map<std::string, int>::iterator it = upper_score_card.begin();
            while (it != upper_score_card.end()) {
                if (it->second > 0) {
                    upper_score += it->second;
                }
                it++;
            }
        }

        /**
         * Updates the score of the lower half of scorecard.
         * 
         * The Yahtzee score card is split in two halves. Bottom
         * half contains the different combos.
        */
        void updateLowerScore() {
            std::map<std::string, int>::iterator it = lower_score_card.begin();
            while (it != lower_score_card.end()) {
                if (it->second > 0) {
                    lower_score += it->second;
                }
                it++;
            }
        }

        /**
         * Checks to see if upper score is high enough for upper bonus.
        */
        void updateUpperBonus() {
            if (upper_score >= 63) {
                upper_bonus = 35;
            }
            else {
                upper_bonus = 0;
            }
        }

        /**
         * Updates each scorecard section and returns the total score.
        */
        void updateTotalScore() {
            total_score = upper_score + upper_bonus + lower_score + yahtzee_bonus;
        }

    public:
        /**
         * Initilizes scorecard values to -1.
        */
        ScoreCard() {
            upper_score_card["One"] = -1;
            upper_score_card["Two"] = -1;
            upper_score_card["Three"] = -1;
            upper_score_card["Four"] = -1;
            upper_score_card["Five"] = -1;
            upper_score_card["Six"] = -1;

            lower_score_card["Three of a Kind"] = -1;
            lower_score_card["Four of a Kind"] = -1;
            lower_score_card["Full House"] = -1;
            lower_score_card["Small Straight"] = -1;
            lower_score_card["Large Straight"] = -1;
            lower_score_card["Yahtzee"] = -1;
            lower_score_card["Chance"] = -1;
        }

        /**
         * Updates the score card.
         * 
         * Returns true when a score is updated. If the category
         * already has a score (not -1), then false is returned
         * since scores cannot be changed.
         * 
         * @param category The category to assign a value to
         * @param val The point total for a given category
         * @return true if successful, false if could not update score
        */
        bool updateScore(std::string category, int val) {
            std::map<std::string, int>::iterator it = upper_score_card.begin();
            while (it != upper_score_card.end()) {
                if (it->first == category) {
                    if (it->second == -1) {
                        it->second = val;
                        return true;
                    } else {
                        return false;
                    }
                }
                it++;
            }

            std::map<std::string, int>::iterator it2 = lower_score_card.begin();
            while (it2 != lower_score_card.end()) {
                if (it2->first == category)
                    if (it2->second == -1) {
                        it2->second = val;
                        return true;
                    } else {
                        return false;
                    }
                it2++;
            }
            return false;
        }

        /**
         * Returns a map with each category on the scorecard.
         * 
         * This function updates the score totals for each section and returns
         * the map of scorecard. Intended to be used to for displaying the score card.
        */
        std::map<std::string, int> getScoreCard() {
            updateUpperScore();
            updateLowerScore();
            updateUpperBonus();
            updateTotalScore();

            std::map<std::string, int> upper_copy = upper_score_card;
            std::map<std::string, int> lower_copy = lower_score_card;

            upper_copy["Upper Subtotal"] = upper_score;
            upper_copy["Upper Bonus"] = upper_bonus;
            upper_copy["Upper Total"] = upper_score + upper_bonus;
            
            upper_copy.merge(lower_copy);
            upper_copy["Yahtzee Bonus"] = yahtzee_bonus;
            upper_copy["Lower Subtotal"] = lower_score + yahtzee_bonus;
            upper_copy["Total Score"] = total_score;

            return upper_copy;
        }

        /**
         * Returns the total score of scorecard.
         * 
         * Intended to be used for win checking at the end of the
         * game.
         * 
         * @return the total score on scorecard.
        */
        int getTotalScore() {
            return total_score;
        }
};