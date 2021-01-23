#pragma once

#ifndef YAHT_PLAYER
#define YAHT_PLAYER

#include <scorecard.h>

class Player
{
    public:
        Player();
        
        virtual int chooseMove(Dice &dice) = 0;

        virtual ~Player();

    protected:
        ScoreCard _card;
        
};

class HumanPlayer: public Player
{
    public:
        HumanPlayer();

        int chooseMove(Dice &dice) override;

        ~HumanPlayer();
    
    private:
        std::set<int> _findValidCombos(Dice &dice);
};

class AIPlayer: public Player
{
    public:
        AIPlayer();

        int chooseMove(Dice &dice) override;

        ~AIPlayer();
};

#endif