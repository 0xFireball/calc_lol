//
// Created by Nihal Talur on 3/14/2017.
//

#pragma once

#include <string>
#include <vector>

#include "charclassifier.h"
#include "Token.h"

class CTCLexer {
public:
    CTCLexer(std::string source);
    std::vector<Token> tokenize_source();

protected:
    bool end_of_code();
    void read_tokens(std::string& working, CharType readType);
    void read_tokens_until(std::string& working, CharType stopType);
    CharType peek_next_char_type();
    char peek_next_char();
    char take_next_char();
    void skip_character(CharType skipType);

private:
    std::string source_code = "";
    int read_pos = 0;
};

