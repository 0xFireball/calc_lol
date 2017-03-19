
#pragma once

#include "StatementSequenceNode.h"
#include "ExpressionNode.h"

class WhileLoopNode : public StatementSequenceNode {
public:
    WhileLoopNode(std::unique_ptr<ExpressionNode>&& expression) : expr(std::move(expression)) {
    }

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    std::unique_ptr<ExpressionNode> expr;
};

