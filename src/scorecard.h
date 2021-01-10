#pragma once

#ifndef YAHT_CARD
#define YAHT_CARD

#include <dice.h>

class ScoreCard
{
    public:
        // variables
        int score;
        int categories[13]; 

        // functions
        bool enterScore(Combos c, Dice &dice);

        // constructor
        ScoreCard();

    private:
        // variables
        int _nScore;
        bool _bonus;

        // scores
        void _scoreN(Dice &dice, int n);
        void _scoreTotal(Dice &dice);
};

#endif