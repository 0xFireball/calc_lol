
#pragma once

#include "AstNode.h"
#include "ExpressionNode.h"
#include <string>

class VariableAssignmentNode : public AstNode {
public:
    VariableAssignmentNode(std::string variable_name, ExpressionNode &expression) : varname(variable_name),
                                                                                    expr(expression) {
    }

private:
    std::string varname;
    ExpressionNode &expr;
};

