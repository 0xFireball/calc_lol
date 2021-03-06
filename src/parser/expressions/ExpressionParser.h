
#pragma once

#include <vector>
#include "../../lexer/Token.h"
#include "../ast/ExpressionNode.h"

/**
 * A shunting-yard-based expression parser for CALCLOL
 * */
class ExpressionParser {
public:
    static std::unique_ptr<ExpressionNode> parse(const std::vector<Token> &tokens, Parser *parser);
};