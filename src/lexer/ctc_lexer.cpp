//
// Created by Nihal Talur on 3/14/2017.
//

#include <string>
#include <vector>

#include "ctc_lexer.h"
#include "charclassifier.h"
#include "Token.h"

CTCLexer::CTCLexer(std::string source) {
    source_code = source;
}

CTCLexer::end_of_code() {
    return read_pos >= source_code.length();
}

std::vector<Token> CTCLexer::tokenize_source() {
    std::vector<Token> tokens;
    std::string working = "";


}

void CTCLexer::read_tokens(std::string working, CharType stopType) {
    while (!end_of_code() && ((peek_next_char_type() & stopType) > 0)) {

    }
}