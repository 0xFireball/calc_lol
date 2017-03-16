
#include "StatementSequenceNode.h"

void StatementSequenceNode::append_statement(AstNode &node) {
    subnodes.push_back(std::shared_ptr(&node));
}
