
#pragma once

#include <memory>

#include "../ExpressionNode.h"
#include "ExpressionOperationType.h"

class BinaryOperationNode : public ExpressionNode {
public:
    BinaryOperationNode(ExpressionOperationType expressionType, ExpressionNode* opA, ExpressionNode* opB)
            : exprType(expressionType),
              opA(opA), opB(opB) {

    }

    ExpressionOperationType get_op_type() const { return exprType; }

    ExpressionNode* get_op_A() const { return opA.get(); }
    ExpressionNode* get_op_B() const { return opB.get(); }

    virtual void emit_code(CodeEmitter& emitter) {}

private:
    ExpressionOperationType exprType;
    std::unique_ptr<ExpressionNode> opA;
    std::unique_ptr<ExpressionNode> opB;
};
