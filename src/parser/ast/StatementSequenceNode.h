//
// Created by Nihal.Talur19 on 3/14/2017.
//

#pragma once

#include <vector>
#include <algorithm>
#include "AstNode.h"

class StatementSequenceNode {
public:
    StatementSequenceNode() {}

    StatementSequenceNode(std::vector<AstNode> sequence_nodes) : subnodes(std::move(sequence_nodes)) {

    }

    std::vector<AstNode> get_sub_nodes() { return subnodes; }

    void append_statement(AstNode node);

private:
    std::vector<AstNode> subnodes;
};