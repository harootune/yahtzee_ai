#include <iostream>
#include <dice.h>

Dice::Dice()
{
    for (int i = 0; i < 5; i++)
    {
        places[i] = (rand() % 6) + 1;
    };

    for (int j = 0; j < 6; j++)
    {
        counts[j] = 0;
    };

    combos.clear();
};

int Dice::total()
{
    int acc = 0;

    for (int i = 0; i < 5; i++)
    {
        acc += places[i];
    };

    return acc;
};

void Dice::reRoll(int place)
{
    places[place] = (rand() % 6) + 1;
    _findCombos();
};

void Dice::_findCombos()
{
    combos.clear();

    _findNs();
    _findFlushes();
    _findFullHouse();
};

void Dice::_findNs()
{
    int accs[6] {0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++)
    {
        accs[places[i] - 1]++;
    };

    for (int j = 0; j < 6; j++)
    {
        if (accs[j] >= 2)
        {
            combos.insert(j);
            counts[j] = accs[j];
        };

        if (accs[j] >= 3)
        {
            combos.insert(Combos::THREE_OAK);
        };

        if (accs[j] >= 4)
        {
            combos.insert(Combos::FOUR_OAK);
        };

        if (accs[j] == 5)
        {
            combos.insert(Combos::YAHTZEE);
        };
    };
};

void Dice::_findFlushes()
{
    int len = 0;
    int flushString[5] {0};

    for (int i = 0; i < 5; i++)
    {
        flushString[places[i] - 1] = 1;
    };

    for (int j = 0; j < 5; j++)
    {
        if (flushString[j] == 1)
        {
            len++;
        }
        else
        {
            len = 0;
        };
    };

    if (len >= 4)
    {
        combos.insert(Combos::SHORT_FLUSH);
    };

    if (len >= 5)
    {
        combos.insert(Combos::FLUSH);
    };
};

void Dice::_findFullHouse()
{
    bool two = false;
    bool three = false;
    int accs[5] {0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++)
    {
        accs[places[i] - 1]++;
    };

    for (int j = 0; j < 5; j++)
    {
        if (accs[j] == 2)
        {
            two = true;
        }
        else if (accs[j] == 3)
        {
            three = true;
        };
    };

    if (two && three)
    {
        combos.insert(Combos::FULL_HOUSE);
    };
};