
#pragma once

#include "ast/ProgramNode.h"
#include "tai/TAIProgram.h"

class SyntaxTreeLinearizer {
public:
    SyntaxTreeLinearizer(std::shared_ptr<ProgramNode> syntax_tree) : ast(syntax_tree) {
    }

    std::shared_ptr<TAIProgram> linearize_syntax_tree();

private:
    std::shared_ptr<ProgramNode> ast;
};
