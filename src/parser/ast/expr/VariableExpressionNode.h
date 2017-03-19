//
// Created by Quinn.Tucker18 on 3/17/2017.
//

#pragma once

#include "../ExpressionNode.h"

class VariableExpressionNode : public ExpressionNode {
public:
    VariableExpressionNode(std::string variable): varName(variable) {

    }

    std::string get_var_name() const { return varName; }

    virtual void emit_code(CodeEmitter& emitter) {}

    bool is_constant() const override {
        return false;
    }

    std::string to_string() const {
        return varName;
    }

private:
    std::string varName;
};
