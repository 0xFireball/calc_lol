//
// Created by Nihal.Talur19 on 3/14/2017.
//

#include <vector>
#include <algorithm>
#include "Token.h"

bool identifier_is_keyword(std::string identifier) {
    std::vector<std::string> keywords = {"if", "num", "str", "return", "void", "while"};
    return std::find(keywords.begin(), keywords.end(), identifier) != keywords.end();
}