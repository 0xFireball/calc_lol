
#pragma once

#include <vector>
#include <memory>
#include "AstNode.h"
#include "../../lexer/Token.h"
#include "../Parser.h"

class ExpressionNode : public AstNode {
public:
    static std::unique_ptr<ExpressionNode> create_from_tokens(std::vector<Token> &tokens, Parser *parser);

    virtual bool is_constant() const = 0;
    virtual int get_constant_value() const {
        throw std::runtime_error("ExpressionNode isn't constant!");
    }

    virtual std::string to_string() const = 0;
    
protected:
    ExpressionNode() {}
};
