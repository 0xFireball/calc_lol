
#include <vector>
#include <algorithm>
#include <map>
#include "Token.h"

std::map<std::string, bool> keyword_map = {
        {"if" : false},
        {"while", false},
        {"return", false},
        {"int", true},
        {"float", true},
        {"void", true}
};

bool identifier_is_keyword(std::string identifier) {
    return keyword_map.count(identifier) > 0;
}

bool keyword_is_type_keyword(std::string keyword) {
    return keyword_map[keyword];
}