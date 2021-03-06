
#pragma once

#include <string>

enum class TokenKind {
    INVALID,

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
bool keyword_is_type_keyword(std::string keyword);

class Token {
public:
    Token():kind(TokenKind::INVALID), content() {}
    Token(TokenKind kind, std::string content):kind(kind), content(content) {
        
    }

    TokenKind get_kind() const { return kind; }
    const std::string& get_content() const { return content; }

private:
    std::string content;
    TokenKind kind;
};
