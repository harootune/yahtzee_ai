#include <algorithm>
#include <string>
#include <stdexcept>
#include <scorecard.h>

ScoreCard::ScoreCard()
{
    score = 0;
    _nScore = 0;
    _bonus = false;
    std::fill(categories, categories + 13, 0);
};

bool ScoreCard::enterScore(Combos c, Dice &dice)
{
    if (categories[c] == 1)
    {
        return false;
    }
    else
    {
        categories[c] = 1;

        if (c < Combos::THREE_OAK)
        {
            _scoreN(dice, c);
        }
        else if (c < Combos::SHORT_FLUSH)
        {
            _scoreTotal(dice);
        }
        else if (c == Combos::SHORT_FLUSH)
        {
            score += 30;
        }
        else if (c == Combos::FLUSH)
        {
            score += 40;
        }
        else if (c == Combos::FULL_HOUSE)
        {
            score += 25;
        }
        else if (c == Combos::YAHTZEE)
        {
            score += 50;
        }
        else
        {
            throw std::invalid_argument("Invalid combo specified" + std::to_string(c));
        };
    };

    return true;
}; 

void ScoreCard::_scoreN(Dice &dice, int n)
{
    score += dice.counts[n];
    _nScore += dice.counts[n];

    if (_nScore > 63 && !_bonus)
    {
        _bonus = true;
        score += 35;
    };
};

void ScoreCard::_scoreTotal(Dice &dice)
{
    score += dice.total();
};