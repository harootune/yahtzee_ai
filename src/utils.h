#pragma once

#ifndef YAHT_UTILS
#define YAHT_UTILS

#include <vector>
#include <map>

namespace Utils
{
    extern std::vector<std::string> ComboLabels;
    extern std::map<std::string, int> ComboCodes;

    std::string codeToLabel(int code);
    int labelToCode(std::string label);
    
    bool validateCode;
};

#endif