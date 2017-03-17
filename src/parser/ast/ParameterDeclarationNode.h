
#pragma once

#include <string>
#include "AstNode.h"

class ParameterDeclarationNode : public AstNode {
public:
    ParameterDeclarationNode(std::string var_type, std::string var_name) : type(var_type), name(var_name) {

    }

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    std::string type;
    std::string name;
};

