#pragma once
/**
 * Class to represent one 6-sided dice.
*/
class Dice {
    private:
        /**
         * Class attribute declaration.
        */
        int value = -1;
        bool held = false;
    
    public:
        /**
         * Sets the value of the dice.
         * 
         * @param val the integer value of the dice.
        */
        void setValue(int val) {
            value = val;
        }

        /**
         * Returns the value of the dice.
         * 
         * @returns the integer value of the dice.
        */
        int getValue() {
            return value;
        }

        /**
         * Sets the status of the 'held' attribute.
         * 
         * Held represents whether or not the player
         * wants to roll the dice on the next roll. If
         * true, then the dice will not be rolled. Default
         * value is false for each dice.
         * 
         * @param val the boolean value to assign to held
        */
        void setHeld(bool val) {
            held = val;
        }

        /**
         * Getter for the held attribute.
         * 
         * @return the held object attribute
        */
        bool getHeld() {
            return held;
        }
};