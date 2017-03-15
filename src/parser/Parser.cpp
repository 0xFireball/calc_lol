
#include <string>
#include "Parser.h"
#include "ast/VariableAssignmentNode.h"
#include "ast/ExpressionNode.h"

Parser::Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {

}

std::shared_ptr<StatementSequenceNode> Parser::peek_scope() {
    return scopes.top();
}

ProgramNode Parser::parse_to_ast() {
    scopes.push(std::shared_ptr<StatementSequenceNode>(new ProgramNode()));

    while (!at_program_end()) {
        auto upcomingToken = peek_next_token();
        switch (upcomingToken.get_kind()) {
            case TokenKind::KEYWORD: {
                Token keyword = take_token();
                bool atGlobalScope = scopes.size() == 1;
                // TODO
                break;
            }
            case TokenKind::IDENTIFIER: {
                Token identifier = take_token();
                auto nextToken = peek_next_token();
                if (nextToken.get_kind() == TokenKind::OPERATOR && nextToken.get_content() == "=") {
                    // assignment operator
                    take_token(); // eat the assignment operator
                    std::vector<Token> valueExpression = read_until_statement_end();
                    peek_scope()->append_statement(VariableAssignmentNode(identifier.get_content(), ExpressionNode::create_from_tokens(valueExpression)));
                }
            }
        }
    }

    ProgramNode ret = static_cast<ProgramNode &>(*scopes.top());
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
