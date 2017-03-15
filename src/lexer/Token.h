//
// Created by Nihal.Talur19 on 3/14/2017.
//

#pragma once

#include <string>

enum class TokenKind {
    ARG_SEP,

    // Braces

    ROUND_BRACE,
    SQUARE_BRACE,
    CURLY_BRACE,
    CLOSE_ROUND_BRACE,
    CLOSE_SQUARE_BRACE,
    CLOSE_CURLY_BRACE,

    IDENTIFIER,
    KEYWORD,

    // Literals

    NUMBER_LITERAL,
    STRING_LITERAL,

    OPERATOR
};

class Token {
public:
    Token(TokenKind kind, std::string content) {
        this->kind = kind;
        this->content = content;
    }

private:
    std::string content;
    TokenKind kind;
};
