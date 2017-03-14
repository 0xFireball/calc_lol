//
// Created by Nihal Talur on 3/14/2017.
//

#pragma once

#include "../util/bitmath.h"

enum class CharType {
    ALPHA = 1 << 0,
    NUMERIC = 1 << 1,
    INLINE_SPACE = 1 << 2,
    NEWLINE = 1 << 3,
    OPERATOR = 1 << 4,
    OPEN_BRACE = 1 << 5,
    CLOSE_BRACE = 1 << 6,
    ARG_SEP = 1 << 7, // Comma
    STMT_SEP = 1 << 8, // Semicolon
    MEMBER_ACCESS = 1 << 9, // Period (.)
    STRING_DELIM = 1 << 10,

    UNKNOWN = 1 << 31,

    // Compound
    ALPHANUMERIC = (1 << 1) | (1 << 0), // alpha and numeric
    DECIMALNUMERIC = (1 << 1) | (1 << 9), // numeric and member access
    WHITESPACE = (1 << 2) | (1 << 3), // Inline whitespace or newline
    BRACE = (1 << 5) | (1 << 6), // for grouping, opening and close brace
    META_CHAR = (1 << 4) | ((1 << 5) | (1 << 6)) | (1 << 7) | (1 << 8) |
                (1 << 9) // special meaning: operator, brace, argsep, stmtsep, member access
};

CharType classify_char(char c);