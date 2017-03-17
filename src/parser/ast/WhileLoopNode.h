
#pragma once

#include "StatementSequenceNode.h"
#include "ExpressionNode.h"

class WhileLoopNode : public StatementSequenceNode {
public:
    WhileLoopNode(std::shared_ptr<ExpressionNode> expression) : expr(expression) {
    }

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    std::shared_ptr<ExpressionNode> expr;
};

