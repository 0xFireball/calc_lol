//
// Created by Nihal.Talur19 on 3/14/2017.
//

#include "StatementSequenceNode.h"

void StatementSequenceNode::append_statement(AstNode node) {
    subnodes.push_back(node);
}
