//
// Created by Nihal Talur on 3/14/2017.
//

#include <string>
#include <vector>

#include "ctc_lexer.h"
#include "Token.h"

CTCLexer::CTCLexer(std::string source):source_code(source) {
    
}

bool CTCLexer::end_of_code() {
    return read_pos >= source_code.length();
}

std::vector<Token> CTCLexer::tokenize_source() {
    std::vector<Token> tokens;
    std::string working = "";

    while (!end_of_code()) {
        
    }

    return tokens;
}

CharType CTCLexer::peek_next_char_type() {
    return classify_char(peek_next_char());
}

char CTCLexer::peek_next_char() {
    return source_code[read_pos];
}

char CTCLexer::take_next_char() {
    char c = peek_next_char();
    ++read_pos;
    return c;
}

void CTCLexer::read_tokens(std::string &working, CharType readType) {
    while (!end_of_code() && (((int) peek_next_char_type() & (int) readType) > 0)) {
        working += take_next_char();
    }
}

void CTCLexer::read_tokens_until(std::string &working, CharType stopType) {
    CharType next_type = peek_next_char_type();
    while (!end_of_code() && (((int) peek_next_char_type() & (int) stopType) == 0)) {
        working += take_next_char();
        next_type = peek_next_char_type();
    }
}

void CTCLexer::skip_character(CharType skipType) {
    while (((int) peek_next_char_type() & (int) skipType) > 0) {
        take_next_char();
    }
}
