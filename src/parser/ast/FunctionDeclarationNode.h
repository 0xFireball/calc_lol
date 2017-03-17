
#pragma once

#include <string>
#include <vector>
#include "ParameterDeclarationNode.h"
#include "StatementSequenceNode.h"

enum class FunctionBodyType {
    CALCLOL,
    Native
};

class FunctionDeclarationNode : public StatementSequenceNode {
public:

    FunctionDeclarationNode(std::string function_name) : name(function_name) {
    }

    void add_parameter(const ParameterDeclarationNode &param) {
        parameters.push_back(param);
    }

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    std::string name;
    std::vector<ParameterDeclarationNode> parameters;
};

