
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

std::unique_ptr<ExpressionNode> ExpressionParser::parse(const std::vector<Token> &tokens) {
    /// convert to postfix form
    std::queue<Token> postfixQueue;
    std::stack<Token> opStack;
    for (const Token& tok : tokens) {
        switch (tok.get_kind()) {
            case TokenKind::NUMBER_LITERAL:
            case TokenKind::IDENTIFIER:
                postfixQueue.push(tok);
                break;
            /* TODO: function token: push onto opStack */
            case TokenKind::ARG_SEP:
                // TODO: handle not encountering a parenthesis (syntax error)
                while (opStack.top().get_kind() != TokenKind::ROUND_BRACE) {
                    postfixQueue.push((opStack.top())); // silence stupid editor bug
                    opStack.pop();
                }
                break;
            case TokenKind::OPERATOR: {
                bool leftAssoc = isLeftAssociative(tok.get_content());
                int prec = precedence(tok.get_content());
                Token o2;
                while (opStack.size()>0 && (o2 = opStack.top()).get_kind() == TokenKind::OPERATOR &&
                       (leftAssoc ? prec <= precedence(o2.get_content()) : prec < precedence(o2.get_content()))) {
                    postfixQueue.push(o2);
                    opStack.pop();
                }
                opStack.push(tok);
                break;
            }
            case TokenKind::ROUND_BRACE: // '('
                opStack.push(tok);
                break;
            case TokenKind::CLOSE_ROUND_BRACE: // ')'
                // TODO: handle not encountering a parenthesis (syntax error)
                while (opStack.top().get_kind() != TokenKind::ROUND_BRACE) {
                    postfixQueue.push((opStack.top())); // silence stupid editor bug
                    opStack.pop();
                }
                opStack.pop();
                // TODO: if opStack.top() is a function token, pop it onto the output queue
                break;
            default:
                throw std::runtime_error("bad token in expression: "+tok.get_content());
        }
    }
    while (opStack.size() > 0) {
        if (opStack.top().get_kind() == TokenKind::ROUND_BRACE)
            throw std::runtime_error("mismatched parentheses in expression");
        postfixQueue.push((opStack.top()));
        opStack.pop();
    }

    /// build ExpressionNode
    std::stack<std::unique_ptr<ExpressionNode>> exprStack;
    while (postfixQueue.size() > 0) {
        Token tok = postfixQueue.front();
        postfixQueue.pop();
        if (tok.get_kind() == TokenKind::NUMBER_LITERAL) {
            exprStack.push(std::make_unique<ConstantExpressionNode>(std::stoi(tok.get_content())));
        } // TODO
    }

    if (exprStack.size() != 1) throw std::runtime_error("bad expression");
    return std::move(exprStack.top());
}
