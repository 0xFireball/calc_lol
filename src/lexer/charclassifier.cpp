
#include "charclassifier.h"

CharType classify_char(char c) {
    // small sets first
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '&':
        case '|':
        case '=':
            return CharType::OPERATOR;
        case '(':
        case '[':
        case '{':
            return CharType::OPEN_BRACE;

        case ')':
        case ']':
        case '}':
            return CharType::CLOSE_BRACE;

        case '"':
            return CharType::STRING_DELIM;

        case ',':
            return CharType::ARG_SEP;

        case ';':
            return CharType::STMT_SEP;

        case '\r':
        case '\n':
            return CharType::NEWLINE;

        case '.':
            return CharType::MEMBER_ACCESS;

        case '_': //Technically you can start an identifier with this
            return CharType::ALPHA;

        case ' ':
        case '\t':
            return CharType::INLINE_SPACE;
    }

    // now categories
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return CharType::ALPHA;
    } else if (c >= '0' && c <= '9') {
        return CharType::NUMERIC;
    }

    return CharType::UNKNOWN;
}