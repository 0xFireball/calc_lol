
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