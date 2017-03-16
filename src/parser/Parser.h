
#pragma once

#include <vector>
#include <stack>

#include "../lexer/Token.h"
#include "../parser/ast/ProgramNode.h"
#include "../parser/ast/StatementSequenceNode.h"
#include <stdexcept>
#include <memory>

class UnexpectedTokenException : public std::logic_error {
public:
    UnexpectedTokenException(std::string msg) : std::logic_error(msg) {};
};

class Parser {
public:
    Parser(std::vector<Token> tokens);

    std::shared_ptr<ProgramNode> parse_to_ast();

protected:
    std::shared_ptr<StatementSequenceNode> peek_scope();

    bool at_program_end();

    std::vector<Token> read_until_token(TokenKind endKind, bool eatEnd = true);

    std::vector<Token> read_until_statement_end();

    Token read_expected_token(TokenKind kind);

    Token peek_next_token();

    Token take_token();

    std::vector<Token> read_token_sequence(std::vector<TokenKind> expectedTokenKinds, bool eatEnd = true);

private:
    std::vector<Token> tokens;
    int read_pos = 0;
    std::stack<std::shared_ptr<StatementSequenceNode>> scopes;
};
