#include "../src/dice.h"
#include "../src/scorecard.h"
#include <iostream>
#include <time.h>

int main()
{
    srand(time(0));
    Dice d = Dice();
    d.reRoll(3);
    std::cout << "Foo" << std::endl;
};

