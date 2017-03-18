
#include "ExpressionNode.h"
#include "../expressions/ExpressionParser.h"
#include "../Parser.h"

std::unique_ptr<ExpressionNode> ExpressionNode::create_from_tokens(std::vector<Token> &tokens, Parser *parser) {
    return ExpressionParser().parse(tokens, parser);
}
