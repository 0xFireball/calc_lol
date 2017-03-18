
#pragma once

#include "../parser/ast/ProgramNode.h"

class PreOptimizer {
public:
    PreOptimizer(ProgramNode* program_ast) : syntax_tree(program_ast) {
    }

    void optimize_syntax_tree();

private:
    ProgramNode* syntax_tree;
};