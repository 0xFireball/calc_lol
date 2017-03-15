
#pragma once

#include "StatementSequenceNode.h"

// A node representing the whole program; this should be the AST root
class ProgramNode : public StatementSequenceNode {
public:
    ProgramNode() : StatementSequenceNode() {}
};
