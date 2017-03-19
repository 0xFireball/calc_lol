//
// Created by Quinn.Tucker18 on 3/18/2017.
//

#pragma once

#include "../ExpressionNode.h"

class FunctionCallNode: public ExpressionNode {
public:
    using paramlist_t = std::vector<std::unique_ptr<ExpressionNode>>;

    FunctionCallNode(std::string function, paramlist_t&& args):funcName(function), arguments(std::move(args)) {
    }

    virtual void emit_code(CodeEmitter& emitter) {}

    std::string to_string() const {
        std::string str = funcName + '(';
        for (size_t i = 0; i < arguments.size(); i++) {
            if (i != 0) str += ", ";
            str += arguments[i]->to_string();
        }
        str += ')';
        return str;
    }

private:
    std::string funcName;
    paramlist_t arguments;
};