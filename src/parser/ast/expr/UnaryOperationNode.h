//
// Created by Nihal.Talur19 on 3/14/2017.
//

#pragma once

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class UnaryOperationNode : ExpressionNode {
public:
    UnaryOperationNode(ExpressionOperationType expressionType, ExpressionNode operand)
            : exprType(expressionType),
              opA(operand) {

    }

    ExpressionOperationType get_expr_type() { return exprType; }

    ExpressionNode get_operand() { return opA; }

private:
    ExpressionOperationType exprType;
    ExpressionNode opA;
};
