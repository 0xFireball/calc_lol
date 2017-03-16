
#pragma once

#include <string>
#include <vector>
#include "AstNode.h"
#include "ParameterDeclarationNode.h"

enum class FunctionBodyType {
    CALCLOL,
    Native
};

class FunctionDeclarationNode : public AstNode {
public:

    FunctionDeclarationNode(std::string function_name) : name(function_name) {
    }

    virtual void emit_code(CodeEmitter& emitter) {}

private:
    std::string name;
    std::vector<ParameterDeclarationNode> parameters;
};

