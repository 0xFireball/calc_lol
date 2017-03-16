
#pragma once

#include "AstNode.h"
#include "ExpressionNode.h"
#include <string>

class VariableAssignmentNode : public AstNode {
public:
    VariableAssignmentNode(std::string variable_name, const ExpressionNode &expression) : var_name(variable_name),
                                                                                    expr(expression) {
    }
    
    virtual void emit_code(CodeEmitter& emitter) {}

private:
    std::string var_name;
    const ExpressionNode &expr;
};
