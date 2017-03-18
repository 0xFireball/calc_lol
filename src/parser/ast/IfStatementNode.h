
#pragma once

#include "StatementSequenceNode.h"
#include "ExpressionNode.h"

class IfStatementNode : public StatementSequenceNode {
public:
    IfStatementNode(std::shared_ptr<ExpressionNode> expression) : expr(expression) {
    }

    virtual void emit_code(CodeEmitter &emitter);

private:
    std::shared_ptr<ExpressionNode> expr;
};

