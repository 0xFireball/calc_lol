
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
    BinaryOperationNode(ExpressionOperationType expressionType,
                        std::unique_ptr<ExpressionNode>&& opA, std::unique_ptr<ExpressionNode>&& opB)
            : exprType(expressionType),
              opA(std::move(opA)), opB(std::move(opB)) {

    }

    ExpressionOperationType get_op_type() const { return exprType; }

    ExpressionNode* get_op_A() const { return opA.get(); }
    ExpressionNode* get_op_B() const { return opB.get(); }

    virtual void emit_code(CodeEmitter& emitter) {}

    std::string to_string() const {
        constexpr char ops[] = "+-*/%";
        return '(' + opA->to_string() + ' '+ops[(int)exprType]+' ' + opB->to_string() + ')';
    }

private:
    ExpressionOperationType exprType;
    std::unique_ptr<ExpressionNode> opA;
    std::unique_ptr<ExpressionNode> opB;
};
