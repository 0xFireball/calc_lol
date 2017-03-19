
#pragma once

#include "AstNode.h"
#include "ExpressionNode.h"
#include <string>

class VariableAssignmentNode : public AstNode {
public:
    VariableAssignmentNode(std::string variable_name, std::unique_ptr<ExpressionNode>&& expression) :
            var_name(variable_name), expr(std::move(expression)) {
    }
    
    virtual void emit_code(CodeEmitter& emitter) {}

private:
    std::string var_name;
    std::unique_ptr<ExpressionNode> expr;
};
