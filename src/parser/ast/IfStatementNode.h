
#pragma once

#include "StatementSequenceNode.h"
#include "ExpressionNode.h"

class IfStatementNode : public StatementSequenceNode {
public:
    IfStatementNode(std::unique_ptr<ExpressionNode>&& expression) : expr(std::move(expression)) {
    }

    virtual void emit_code(CodeEmitter &emitter);

private:
    std::unique_ptr<ExpressionNode> expr;
};

