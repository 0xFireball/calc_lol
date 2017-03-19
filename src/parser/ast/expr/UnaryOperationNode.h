
#pragma once

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class UnaryOperationNode : public ExpressionNode {
public:
    UnaryOperationNode(ExpressionOperationType expressionType, ExpressionNode* operand)
            : exprType(expressionType),
              opA(operand) {

    }

    ExpressionOperationType get_expr_type() const { return exprType; }

    ExpressionNode* get_operand() const { return opA.get(); }

    bool is_constant() const override {
        return opA->is_constant();
    }
    int get_constant_value() const override {
        if (exprType == ExpressionOperationType::NEGATE)
            return -opA->get_constant_value();
        throw std::runtime_error("Bad unary operator");
    }

    virtual void emit_code(CodeEmitter& emitter) {}

private:
    ExpressionOperationType exprType;
    std::unique_ptr<ExpressionNode> opA;
};
