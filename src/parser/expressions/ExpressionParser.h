
#pragma once

#include <vector>
#include "../../lexer/Token.h"
#include "../ast/ExpressionNode.h"

/**
 * A shunting-yard-based expression parser for CALCLOL
 * */
class ExpressionParser {
public:
    static std::shared_ptr<ExpressionNode> parse(std::vector<Token> &tokens);
};