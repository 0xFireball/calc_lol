
#pragma once

#include <vector>
#include <memory>
#include "AstNode.h"
#include "../../lexer/Token.h"

class ExpressionNode : public AstNode {
public:
    static std::unique_ptr<ExpressionNode> create_from_tokens(std::vector<Token> &tokens);

    virtual std::string to_string() const {
        throw std::runtime_error("not implemented in this class!");
    }
    
protected:
    ExpressionNode() {}
};
