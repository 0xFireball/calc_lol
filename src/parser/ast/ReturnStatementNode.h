
#pragma once

#include "AstNode.h"
#include "ExpressionNode.h"

class ReturnStatementNode : public AstNode {
public:
    ReturnStatementNode(std::shared_ptr<ExpressionNode> expression) : expr(expression) {

    }

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    std::shared_ptr<ExpressionNode> expr;
};

