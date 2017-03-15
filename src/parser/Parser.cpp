
#include "Parser.h"

Parser::Parser(std::vector <Token> tokens) : tokens(std::move(tokens)) {

}

StatementSequenceNode Parser::peek_scope() {
    return scopes.top();
}

ProgramNode Parser::parse_to_ast() {
    scopes.push(ProgramNode());

    return (ProgramNode)scopes.pop();
}

bool Parser::at_program_end() {
    return read_pos >= tokens.length();
}