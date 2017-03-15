
#include <string>
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

Token Parser::read_expected_token(TokenKind kind) {
    auto upcomingToken = peek_next_token();
    auto t_kind = upcomingToken.get_kind();
    if (t_kind == kind) {
        // valid, advance and return
        return take_token();
    } else {
        throw UnexpectedTokenException("Unexpected token: " + std::to_string((int) t_kind));
    }
}

std::vector<Token> Parser::read_until_token(TokenKind endKind) {
    std::vector<Token> read_tokens;
    auto upcomingToken = peek_next_token();
    while (!at_program_end() && !(upcomingToken.get_kind() != endKind)) {
        read_tokens.push_back(take_token());
        upcomingToken = peek_next_token();
    }
    take_token(); // eat the statement separator
}

std::vector<Token> Parser::read_until_statement_end() {
    return read_until_token(TokenKind::STMT_SEP);
}
