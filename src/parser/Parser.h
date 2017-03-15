
#pragma once

#include <vector>
#include <stack>

#include "../lexer/Token.h"
#include "../parser/ast/ProgramNode.h"
#include "../parser/ast/StatementSequenceNode.h"

class Parser {
public:
    Parser(std::vector <Token> tokens);

    ProgramNode parse_to_ast();

protected:
    StatementSequenceNode peek_scope();

    bool at_program_end();

private:
    std::vector <Token> tokens;
    int read_pos = 0;
    std::stack <StatementSequenceNode> scopes;
};
