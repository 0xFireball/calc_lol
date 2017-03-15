
#pragma once

#include "AstNode.h"
#include "ExpressionNode.h"
#include <string>

class VariableAssignmentNode : AstNode {
public:
    VariableAssignmentNode(std::string variable_name, ExpressionNode &expression) : varname(variable_name),
                                                                                    expr(expression) {
    }

private:
    std::string varname;
    ExpressionNode &expr;
};

