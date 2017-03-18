
#pragma once

#include "../parser/ast/ProgramNode.h"

class PreOptimizer {
public:
    PreOptimizer(std::shared_ptr<ProgramNode> program_ast) : syntax_tree(program_ast) {
    }

    void optimize_syntax_tree();

private:
    std::shared_ptr<ProgramNode> syntax_tree;
};