
#pragma once

#include <vector>
#include <stack>

#include "../lexer/Token.h"
#include "../parser/ast/ProgramNode.h"
#include "../parser/ast/StatementSequenceNode.h"


#pragma once

#include <stdexcept>

class UnexpectedTokenException : public std::logic_error {
public:
    UnexpectedTokenException(std::string msg) : std::logic_error(msg) {};
};

class Parser {
public:
    Parser(std::vector<Token> tokens);

    ProgramNode parse_to_ast();

protected:
    StatementSequenceNode peek_scope();

    bool at_program_end();

    std::vector<Token> read_until_token(TokenKind endKind);

    std::vector<Token> read_until_statement_end();

    Token read_expected_token(TokenKind kind);

    Token peek_next_token();

    Token take_token();

    std::vector<Token> read_token_sequence(TokenKind expectedTokenKinds[]);

private:
    std::vector<Token> tokens;
    int read_pos = 0;
    std::stack<StatementSequenceNode> scopes;
};
