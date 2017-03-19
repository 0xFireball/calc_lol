
#include "ExpressionParser.h"
#include <queue>
#include <stack>

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

#include "../../util/NotImplementedException.h"
#include "../ast/expr/BinaryOperationNode.h"
#include "../ast/expr/UnaryOperationNode.h"
#include "../ast/expr/ConstantExpressionNode.h"
#include "../ast/expr/VariableExpressionNode.h"
#include "../ast/expr/FunctionCallNode.h"
#include "../Parser.h"

#include "../../util/container_util.h"

static bool is_left_associative(std::string op) {
    if (op == "+" || op == "-" ||
        op == "*" || op == "/" || op == "%" ||
        op == "&&" || op == "||")
        return true;
    throw std::runtime_error("unrecognized operator: " + op);
}

static int precedence(std::string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/" || op == "%") return 2;
    if (op == "&&") return 3;
    if (op == "||") return 4;
    throw std::runtime_error("unrecognized operator: " + op);
}

std::unique_ptr<ExpressionNode> ExpressionParser::parse(const std::vector<Token> &tokens, Parser *parser) {
    if (tokens.size() == 0) return nullptr;

    /// convert to postfix form
    std::queue<Token> postfixQueue;
    std::stack<Token> opStack;
    std::stack<size_t> arityStack;
    std::map<std::string, size_t> arityMap;
    for (const Token &tok : tokens) {
        switch (tok.get_kind()) {
            case TokenKind::NUMBER_LITERAL:
                if (arityStack.size() && arityStack.top()==0) arityStack.top()++;
                postfixQueue.push(tok);
                break;
            case TokenKind::IDENTIFIER: {
                if (arityStack.size() && arityStack.top()==0) arityStack.top()++;
                auto symbolInfo = parser->resolve_symbol(tok.get_content());
                if (!symbolInfo) throw std::runtime_error("unresolved identifier: "+tok.get_content());
                switch (symbolInfo->kind) {
                    case SymbolKind::VARIABLE:
                        postfixQueue.push(tok);
                        break;
                    case SymbolKind::FUNCTION:
                        opStack.push(tok);
                        break;
                }
                break;
            } case TokenKind::ARG_SEP:
                arityStack.top()++; // TODO: handle invalid ARG_SEP
                // TODO: handle not encountering a parenthesis (syntax error)
                while (opStack.top().get_kind() != TokenKind::ROUND_BRACE) {
                    postfixQueue.push(util::pop(opStack));
                }
                break;
            case TokenKind::OPERATOR: {
                bool leftAssoc = is_left_associative(tok.get_content());
                int prec = precedence(tok.get_content());
                Token o2;
                while (opStack.size() > 0 && (o2 = opStack.top()).get_kind() == TokenKind::OPERATOR &&
                       (leftAssoc ? prec <= precedence(o2.get_content()) : prec < precedence(o2.get_content()))) {
                    postfixQueue.push(o2);
                    opStack.pop();
                }
                opStack.push(tok);
                break;
            }
            case TokenKind::ROUND_BRACE: // '('
                if (opStack.top().get_kind() == TokenKind::IDENTIFIER)
                    arityStack.push(0);
                opStack.push(tok);
                break;
            case TokenKind::CLOSE_ROUND_BRACE: // ')'
                // TODO: handle not encountering a parenthesis (syntax error)
                while (opStack.top().get_kind() != TokenKind::ROUND_BRACE) {
                    postfixQueue.push(util::pop(opStack));
                }
                opStack.pop(); // pop the open parenthesis
                // if opStack.top() is a function token, pop it onto the output queue
                if (opStack.top().get_kind() == TokenKind::IDENTIFIER) {
                    arityMap.emplace(opStack.top().get_content(), util::pop(arityStack));
                    postfixQueue.push(util::pop(opStack));
                }
                break;
            default:
                throw std::runtime_error("bad token in expression: " + tok.get_content());
        }
    }
    while (opStack.size() > 0) {
        if (opStack.top().get_kind() == TokenKind::ROUND_BRACE)
            throw std::runtime_error("mismatched parentheses in expression");
        postfixQueue.push(util::pop(opStack));
    }

    /// build ExpressionNode
    std::stack<std::unique_ptr<ExpressionNode>> exprStack;
    while (postfixQueue.size() > 0) {
        Token tok = util::pop(postfixQueue);
        if (tok.get_kind() == TokenKind::NUMBER_LITERAL) {
            exprStack.push(std::make_unique<ConstantExpressionNode>(std::stoi(tok.get_content())));
        } else if (tok.get_kind() == TokenKind::IDENTIFIER) {
            if (parser->resolve_symbol(tok.get_content())->kind == SymbolKind::VARIABLE) {
                exprStack.push(std::make_unique<VariableExpressionNode>(tok.get_content()));
            } else { // SymbolKind::FUNCTION
                FunctionCallNode::arglist_t args;
                size_t numArgs = arityMap[tok.get_content()];
                for (size_t n = 0; n < numArgs; n++)
                    args.push_back(util::pop(exprStack));
                exprStack.push(std::make_unique<FunctionCallNode>(tok.get_content(), std::move(args)));
            }
        } else if (tok.get_kind() == TokenKind::OPERATOR) {
            ExpressionOperationType op_type = get_operation_type(tok.get_content());
            auto opB = util::pop(exprStack);
            auto opA = util::pop(exprStack);
            exprStack.push(std::make_unique<BinaryOperationNode>(op_type, std::move(opA), std::move(opB)));
        } else {
            throw std::runtime_error("SOMETHING VERY WRONG I THINK");
        }
    }

    if (exprStack.size() != 1) throw std::runtime_error("bad expression");
    cout << exprStack.top()->to_string() << endl;
    return std::move(exprStack.top());
}
