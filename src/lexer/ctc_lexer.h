//
// Created by Nihal Talur on 3/14/2017.
//

#pragma once

#include <string>
#include <vector>

class CTCLexer {
public:
    CTCLexer(std::vector<std::string>& source_lines);
    std::vector<Token> parse();
};

