//
// Created by Nihal.Talur19 on 3/14/2017.
//

#pragma once

#include <vector>
#include "AstNode.h"
#include "../../lexer/Token.h"

class ExpressionNode : AstNode {
public:
    static ExpressionNode create_from_tokens(std::vector<Token> tokens);
protected:
    ExpressionNode() {}
};