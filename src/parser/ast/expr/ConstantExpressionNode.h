
#pragma once

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class ConstantExpressionNode : public ExpressionNode {
public:
    ConstantExpressionNode(int value) : val(value) {

    }

    virtual void emit_code(CodeEmitter &emitter) {}

    bool is_constant() const override {
        return true;
    }
    int get_constant_value() const override {
        return val;
    }

    std::string to_string() const {
        return std::to_string(val);
    }

private:
    int val;
};
