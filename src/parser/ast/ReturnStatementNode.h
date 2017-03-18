
#pragma once

#include "AstNode.h"
#include "ExpressionNode.h"

class ReturnStatementNode : public AstNode {
public:
    ReturnStatementNode(ExpressionNode* expression) : expr(expression) {

    }
    ReturnStatementNode(std::unique_ptr<ExpressionNode>&& expression) : expr(std::move(expression)) {

    }

    virtual void emit_code(CodeEmitter &emitter);

private:
    std::unique_ptr<ExpressionNode> expr;
};

