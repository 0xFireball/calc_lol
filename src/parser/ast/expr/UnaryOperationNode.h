
#pragma once

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class UnaryOperationNode : public ExpressionNode {
public:
    UnaryOperationNode(ExpressionOperationType expressionType, ExpressionNode operand)
            : exprType(expressionType),
              opA(operand) {

    }

    ExpressionOperationType get_expr_type() { return exprType; }

    ExpressionNode get_operand() { return opA; }

    virtual void emit_code(CodeEmitter& emitter) {}

private:
    ExpressionOperationType exprType;
    ExpressionNode opA;
};
