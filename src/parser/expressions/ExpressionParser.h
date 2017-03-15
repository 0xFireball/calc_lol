//
// Created by Nihal.Talur19 on 3/14/2017.
//

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