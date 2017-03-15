
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
    UnexpectedTokenException() : std::logic_error("The method or operation is not implemented.") {};
};

class Parser {
public:
    Parser(std::vector<Token> tokens);

    ProgramNode parse_to_ast();

protected:
    StatementSequenceNode peek_scope();

    bool at_program_end();

    Token peek_next_token();

    Token take_token();

    std::vector<Token> read_token_sequence(TokenKind expectedTokenKinds[]);

private:
    std::vector<Token> tokens;
    int read_pos = 0;
    std::stack<StatementSequenceNode> scopes;
};
