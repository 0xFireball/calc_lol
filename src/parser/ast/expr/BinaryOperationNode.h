
#pragma once

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class BinaryOperationNode : public ExpressionNode {
public:
    BinaryOperationNode(ExpressionOperationType expressionType, ExpressionNode operandA, ExpressionNode operandB)
            : exprType(expressionType),
              opA(operandA), opB(operandB) {

    }

    ExpressionOperationType get_expr_type() { return exprType; }

    ExpressionNode get_op_A() { return opA; }
    ExpressionNode get_op_B() { return opB; }

    virtual void emit_code(CodeEmitter& emitter) {}

private:
    ExpressionOperationType exprType;
    ExpressionNode opA;
    ExpressionNode opB;
};
