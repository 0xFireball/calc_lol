
#pragma once

#include <vector>
#include "AstNode.h"
#include "../../lexer/Token.h"

class ExpressionNode : public AstNode {
public:
    static ExpressionNode create_from_tokens(std::vector<Token> &tokens);
    
    virtual void emit_code(CodeEmitter& emitter) {}
    
protected:
    ExpressionNode() {}
};
