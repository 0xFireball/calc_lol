
#pragma once

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class ConstantExpressionNode : public ExpressionNode {
public:
    ConstantExpressionNode(int value) : val(value) {

    }

    int get_constant_value() const { return val; }

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    int val;
};
