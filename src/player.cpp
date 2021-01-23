#include <stdexcept>
#include <iostream>
#include <sstream>
#include <player.h>
#include <utils.h>

Player::Player() {};

Player::~Player() {};

HumanPlayer::HumanPlayer()
{
    _card = ScoreCard();
};

int HumanPlayer::chooseMove(Dice dice)
{
    int inputCode;
    std::string inputStr;
    std::set<int> combos = _findValidCombos(dice);

    printf("Current Dice: %d %d %d %d %d\n", dice.places[0], 
                                            dice.places[1],
                                            dice.places[2],
                                            dice.places[3],
                                            dice.places[4]);

    printf("Scoring Combos:\n");
    for (int combo: combos)
    {
        printf("%s: code %d\n", Utils::codeToLabel(combo), combo);
    };

    printf("Remaining Combos: \n");
    for (int i = 0; i < 13; i++)
    {
        if (_card.categories[i] == 0)
        {
            printf("%s: code %d\n", Utils::codeToLabel(i), i);
        };
    };
    
    std::cout << "Input options:" << std::endl;
    if (dice.rolls < 3)
    {
        printf("Reroll: Sequential integers, e.g. 123, 2, 5431 (%d rolls remaining) \n", 3 - dice.rolls);
    };
    std::cout << "Combo: Combo code + 0, e.g 10, 110, 70" << std::endl;

    std::cout << "Please input your move: ";

    std::getline(std::cin, inputStr);
    std::stringstream(inputStr) >> inputCode;

    Utils::

};

std::set<int> HumanPlayer::_findValidCombos(Dice &dice)
{
    std::set<int> validCombos {};
    
    for (int combo: dice.combos)
    {
        if (_card.categories[combo] == 0)
        {
            validCombos.insert(combo);
        };
    };

    return validCombos;
};

AIPlayer::AIPlayer()
{
    _card = ScoreCard();
}