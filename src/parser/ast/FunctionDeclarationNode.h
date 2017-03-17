
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

    FunctionDeclarationNode(std::string function_name, std::string return_type) : name(function_name),
                                                                                  ret_type(return_type) {
    }

    void add_parameter(const ParameterDeclarationNode &param) {
        parameters.push_back(param);
    }

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    std::string name;
    std::string ret_type;
    std::vector<ParameterDeclarationNode> parameters;
};

