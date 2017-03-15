
#include "Parser.h"

Parser::Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {

}

StatementSequenceNode Parser::peek_scope() {
    return scopes.top();
}

ProgramNode Parser::parse_to_ast() {
    scopes.push(ProgramNode());

    ProgramNode ret = static_cast<ProgramNode &>(scopes.top());
    scopes.pop();
    return ret;
}

bool Parser::at_program_end() {
    return read_pos >= tokens.size();
}

std::vector<Token> Parser::read_token_sequence(TokenKind *expectedTokenKinds) {
    // TODO
}

Token Parser::take_token() {
    auto ret = peek_next_token();
    ++read_pos;
    return ret;
}

Token Parser::peek_next_token() {
    return tokens[read_pos];
}
