//
// Created by Nihal.Talur19 on 3/14/2017.
//

#pragma once

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class BinaryOperationNode : ExpressionNode {
public:
    BinaryOperationNode(ExpressionOperationType expressionType, ExpressionNode operandA, ExpressionNode operandB)
            : exprType(expressionType),
              opA(operandA), opB(operandB) {

    }

    ExpressionOperationType get_expr_type() { return exprType; }

    ExpressionNode get_op_A() { return opA; }

    ExpressionNode get_op_B() { return opB; }

private:
    ExpressionOperationType exprType;
    ExpressionNode opA;
    ExpressionNode opB;
};
