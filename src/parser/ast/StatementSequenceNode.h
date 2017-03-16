
#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include "AstNode.h"

class StatementSequenceNode : public AstNode {
public:
    StatementSequenceNode() {}

    StatementSequenceNode(std::vector<std::unique_ptr<AstNode>> sequence_nodes) : subnodes(std::move(sequence_nodes)) {

    }

    std::vector<std::shared_ptr<AstNode>> get_sub_nodes() { return subnodes; }

    void append_statement(AstNode &node);

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    std::vector<std::shared_ptr<AstNode>> subnodes;
};
