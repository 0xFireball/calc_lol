//
// Created by Nihal.Talur19 on 3/14/2017.
//

#pragma once

#include "../../emit/CodeEmitter.h"

class AstNode {
public:
    virtual void emit_code(CodeEmitter emitter);
};
