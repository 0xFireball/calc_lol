//
// Created by Nihal Talur on 3/14/2017.
//

#include <string>
#include <vector>
#include <stdexcept>

#include "ctc_lexer.h"
#include "Token.h"

CTCLexer::CTCLexer(std::string source) {
    source_code = source;
}

bool CTCLexer::end_of_code() {
    return read_pos >= source_code.length();
}

std::vector<Token> CTCLexer::tokenize_source() {
    std::vector<Token> tokens;
    std::string working = "";

    // TODO: Clean up comments or just tokenize them. whatever.

    while (!end_of_code()) {
        // ignore whitespace
        skip_character(CharType::WHITESPACE);
        char nextChar = peek_next_char();
        CharType nextCharType = peek_next_char_type();
        switch (nextCharType) {
            case CharType::ALPHA: //start of identifier
                read_tokens(working, CharType::ALPHANUMERIC);
                if (KeywordToken.IsKeyword(working))
                    tokens.push_back(Token(TokenKind::KEYWORD, working));
                else
                tokens.push_back(Token(TokenKind::IDENTIFIER, working));
                working.clear();
                break;

            case CharType::STRING_DELIM:
                take_next_char(); //Skip the opening quote
                read_tokens_until(working, CharType::STRING_DELIM);
                take_next_char(); //Skip the ending quote
                tokens.push_back(Token(TokenKind::STRING_LITERAL, working));
                working.clear();
                break;

            case CharType::NUMERIC: //start of number literal, allow for decimal numbers too
                read_tokens(working, CharType::DECIMALNUMERIC);
                tokens.push_back(Token(TokenKind::NUMBER_LITERAL, working));
                working.clear();
                break;

            case CharType::OPERATOR:
                //It is an operator
                read_tokens(working, CharType::OPERATOR);
                tokens.push_back(Token(TokenKind::OPERATOR, working));
                working.clear();
                break;

            case CharType::OPEN_BRACE: {
                char c = take_next_char();
                TokenKind braceTokenKind;
                switch (c) {
                    case '(':
                        braceTokenKind = TokenKind::ROUND_BRACE;
                        break;
                    case '[':
                        braceTokenKind = TokenKind::SQUARE_BRACE;
                        break;
                    case '{':
                        braceTokenKind = TokenKind::CURLY_BRACE;
                        break;
                    default:
                        // WTF?
                        break;
                }
                tokens.push_back(Token(braceTokenKind, std::string(1, c)));
                break;
            }

            case CharType::CLOSE_BRACE: {
                char c = take_next_char();
                TokenKind braceTokenKind;
                switch (c) {
                    case '(':
                        braceTokenKind = TokenKind::CLOSE_ROUND_BRACE;
                        break;
                    case '[':
                        braceTokenKind = TokenKind::CLOSE_SQUARE_BRACE;
                        break;
                    case '{':
                        braceTokenKind = TokenKind::CLOSE_CURLY_BRACE;
                        break;
                    default:
                        // WTF?
                        break;
                }
                tokens.push_back(Token(braceTokenKind, std::string(1, c)));
                break;
            }
            case CharType::ARG_SEP:
                tokens.push_back(Token(TokenKind::ARG_SEP, std::string(1, take_next_char())));
                break;

            case CharType::STMT_SEP:
                tokens.push_back(Token(TokenKind::STMT_SEP, std::string(1, take_next_char())));
                break;

            default:
                throw std::runtime_error("The tokenizer found an unidentifiable character: " + nextChar);
        }
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