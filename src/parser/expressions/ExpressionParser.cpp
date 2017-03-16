
#include "ExpressionParser.h"
#include "../../util/NotImplementedException.h"
#include <queue>
#include <stack>

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
                while (stack.top().get_content() != "(") {
                    output.push(stack.top());
                    stack.pop();
                }
                //...
        }
    }

    // [unfinished]
    return nullptr;
}
