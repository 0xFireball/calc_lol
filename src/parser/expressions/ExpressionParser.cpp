
#include "ExpressionParser.h"
#include <queue>
#include <stack>

#include <iostream>

#include "../../util/NotImplementedException.h"
#include "../ast/expr/BinaryOperationNode.h"
#include "../ast/expr/UnaryOperationNode.h"
#include "../ast/expr/ConstantExpressionNode.h"

static bool isLeftAssociative(std::string op) {
    if (op=="+" || op=="-" ||
        op=="*" || op=="/" || op=="%" ||
        op=="&&" || op=="||") return true;
    throw std::runtime_error("bad operator: "+op);
}

static int precedence(std::string op) {
    if (op=="+" || op=="-") return 1;
    if (op=="*" || op=="/" || op=="%") return 2;
    if (op=="&&") return 3;
    if (op=="||") return 4;
    throw std::runtime_error("bad operator: "+op);
}

std::shared_ptr<ExpressionNode> ExpressionParser::parse(const std::vector<Token> &tokens) {
    // convert to postfix form
    std::queue<Token> output;
    std::stack<Token> stack;
    for (const Token& tok : tokens) {
        switch (tok.get_kind()) {
            case TokenKind::NUMBER_LITERAL:
            case TokenKind::IDENTIFIER:
                output.push(tok);
                break;
            /* function token: push onto stack */
            case TokenKind::ARG_SEP:
                // TODO: handle not encountering a parenthesis (syntax error)
                while (stack.top().get_kind() != TokenKind::ROUND_BRACE) {
                    output.push((stack.top())); // silence stupid editor bug
                    stack.pop();
                }
                break;
            case TokenKind::OPERATOR: {
                bool leftAssoc = isLeftAssociative(tok.get_content());
                int prec = precedence(tok.get_content());
                Token o2;
                while (stack.size()>0 && (o2 = stack.top()).get_kind() == TokenKind::OPERATOR &&
                       (leftAssoc ? prec <= precedence(o2.get_content()) : prec < precedence(o2.get_content()))) {
                    stack.pop();
                    output.push(o2);
                }
                stack.push(tok);
                break;
            }
            case TokenKind::ROUND_BRACE: // '('
                stack.push(tok);
                break;
            case TokenKind::CLOSE_ROUND_BRACE: // ')'
                // TODO: handle not encountering a parenthesis (syntax error)
                while (stack.top().get_kind() != TokenKind::ROUND_BRACE) {
                    output.push((stack.top())); // silence stupid editor bug
                    stack.pop();
                }
                stack.pop();
                // TODO: if stack.top() is a function token, pop it onto the output queue
                break;
            default:
                throw std::runtime_error("bad token in expression: "+tok.get_content());
        }
    }
    while (stack.size() > 0) {
        if (stack.top().get_kind() == TokenKind::ROUND_BRACE)
            throw std::runtime_error("mismatched parentheses in expression");
        output.push((stack.top()));
        stack.pop();
    }

    while (output.size()) {
        std::cout << output.front().get_content() << ' ';
        output.pop();
    }
    std::cout << std::endl;

    // [unfinished]
    return nullptr;
}
