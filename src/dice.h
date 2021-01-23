#pragma once

#ifndef YAHT_DICE
#define YAHT_DICE

#include <set>

enum Combos
{
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    THREE_OAK,
    FOUR_OAK,
    CHANCE,
    SHORT_FLUSH,
    FLUSH,
    FULL_HOUSE,
    YAHTZEE,
};

class Dice
{
    public:
        // variables
        int places[5];
        int counts[6];
        int rolls;
        std::set<int> combos;

        // functions
        int total();
        void reRoll(int place);

        // constructor
        Dice();
    
    private:
        // combo finding
        void _findCombos();
        void _findNs();
        void _findFullHouse();
        void _findFlushes();

        // debug
        void _debugMessage();
};

#endif