
#pragma once

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class ConstantExpressionNode : public ExpressionNode {
public:
    ConstantExpressionNode(int value) : val(value) {

    }

    int get_constant_value() const { return val; }

    virtual void emit_code(CodeEmitter &emitter) {}

    std::string to_string() const {
        return std::to_string(val);
    }

private:
    int val;
};
