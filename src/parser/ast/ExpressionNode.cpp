
#include "ExpressionNode.h"
#include "../expressions/ExpressionParser.h"

std::unique_ptr<ExpressionNode> ExpressionNode::create_from_tokens(std::vector<Token> &tokens) {
    return ExpressionParser().parse(tokens);
}
