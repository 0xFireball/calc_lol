
#pragma once

#include <vector>
#include <memory>
#include "AstNode.h"
#include "../../lexer/Token.h"

class ExpressionNode : public AstNode {
public:
    static std::shared_ptr<ExpressionNode> create_from_tokens(std::vector<Token> &tokens);
    
protected:
    ExpressionNode() {}
};
