
#pragma once

#include <vector>
#include "../../lexer/Token.h"
#include "../ast/ExpressionNode.h"

/**
 * A shunting-yard-based expression parser for CALCLOL
 * */
class ExpressionParser {
public:
    ExpressionNode parse(std::vector<Token> tokens);
};