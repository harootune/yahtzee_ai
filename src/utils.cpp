#include <string>
#include <utils.h>


std::vector< std::string > Utils::ComboLabels 
{
    "ones",
    "twos",
    "threes",
    "fours",
    "fives",
    "sixes",
    "three of a kind",
    "four of a kind",
    "chance",
    "short flush",
    "flush",
    "full house",
    "yahtzee"
};

std::map<std::string, int> Utils::ComboCodes 
{
    {"ones", 0},
    {"twos", 1},
    {"threes", 2},
    {"fours", 3},
    {"fives", 4},
    {"sixes", 5},
    {"three of a kind", 6},
    {"four of a kind", 7},
    {"chance", 8},
    {"short flush", 9},
    {"flush", 10},
    {"full house", 11},
    {"yahtzee", 12}
};

std::string Utils::codeToLabel(int code)
{
    return Utils::ComboLabels[code];
};

int Utils::labelToCode(std::string label)
{
    return Utils::ComboCodes[label];
}
