
#pragma once

#include <string>

enum class TokenKind {
    ARG_SEP,
    STMT_SEP,

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

bool identifier_is_keyword(std::string identifier);

class Token {
public:
    Token(TokenKind kind, std::string content):kind(kind), content(content) {
        
    }

    TokenKind get_kind() { return kind; }

private:
    std::string content;
    TokenKind kind;
};
