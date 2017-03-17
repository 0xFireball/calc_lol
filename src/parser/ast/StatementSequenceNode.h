
#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include "AstNode.h"

class StatementSequenceNode : public AstNode {
public:
    using nodelist_t = std::vector<std::unique_ptr<AstNode>>;

    StatementSequenceNode() {}

    StatementSequenceNode(StatementSequenceNode &&other) = default; // moveable
    StatementSequenceNode(const StatementSequenceNode &) = delete; // non-copyable because of the children list stuff

    StatementSequenceNode(nodelist_t &&sequence_nodes) : subnodes(std::move(sequence_nodes)) {

    }

    nodelist_t &get_sub_nodes() { return subnodes; }

    const nodelist_t &get_sub_nodes() const { return subnodes; }

    template<class NodeType, class... ArgT>
    void append_statement(ArgT &&... args) {
        subnodes.push_back(std::make_unique<NodeType>(std::forward<ArgT>(args)...));
    }

    virtual void emit_code(CodeEmitter &emitter) {}

private:
    nodelist_t subnodes;
};
