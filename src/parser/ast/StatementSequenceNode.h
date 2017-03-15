
#pragma once

#include <vector>
#include <algorithm>
#include "AstNode.h"

class StatementSequenceNode : public AstNode {
public:
    StatementSequenceNode() {}

    StatementSequenceNode(std::vector<AstNode> sequence_nodes) : subnodes(std::move(sequence_nodes)) {

    }

    std::vector<AstNode> get_sub_nodes() { return subnodes; }

    void append_statement(AstNode node);
    
    virtual void emit_code(CodeEmitter& emitter) {}

private:
    std::vector<AstNode> subnodes;
};
