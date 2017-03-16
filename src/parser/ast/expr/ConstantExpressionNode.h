
#pragma once

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class ConstantExpressionNode : public ExpressionNode {
public:
    ConstantExpressionNode(double value) :
            val(value) {

    }

    double get_constant_value() { return val; }

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    double val;
};
