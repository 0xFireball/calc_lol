
#pragma once

#include <vector>
#include <stack>
#include <map>

#include "../lexer/Token.h"
#include "../parser/ast/ProgramNode.h"
#include "../parser/ast/StatementSequenceNode.h"
#include <stdexcept>
#include <memory>

class UnexpectedTokenException : public std::logic_error {
public:
    UnexpectedTokenException(std::string msg) : std::logic_error(msg) {};
};

class ParseError : public std::logic_error {
public:
    ParseError(std::string msg) : std::logic_error(msg) {};
};

class CompilationError : public std::logic_error {
public:
    CompilationError(std::string msg) : std::logic_error(msg) {};
};

enum class SymbolKind {
    VARIABLE,
    FUNCTION
};

struct SymbolInformation {
    SymbolInformation(int symbol_scope, SymbolKind symbol_kind, std::string symbol_type) : scope(symbol_scope),
                                                                                           kind(symbol_kind),
                                                                                           type(symbol_type) {

    }

    int scope;
    SymbolKind kind;
    std::string type;
};

using symbolmap_t = std::map<std::string, std::shared_ptr<SymbolInformation>>;

struct ScopeInformation {
    ScopeInformation(ScopeInformation *parent_scope_info, StatementSequenceNode *statement_sequence)
            : statements(statement_sequence), parent_scope(parent_scope_info) {

    }

    ScopeInformation *parent_scope;

    StatementSequenceNode *statements;
    symbolmap_t symbol_map;
};

class Parser {
public:
    Parser(std::vector<Token> tokens);

    std::shared_ptr<ProgramNode> parse_to_ast();

    std::shared_ptr<SymbolInformation> resolve_symbol(std::string identifier);

protected:
    StatementSequenceNode *peek_scope_statements();

    ScopeInformation *peek_scope_info();

    bool symbol_exists(std::string identifier, SymbolKind kind);

    std::shared_ptr<SymbolInformation> resolve_symbol_in_scope(std::string identifier, ScopeInformation* scope_info);

    bool at_program_end();

    std::vector<Token> read_until_token(TokenKind endKind, bool eatEnd = true);

    std::vector<Token> read_until_statement_end();

    Token read_expected_token(TokenKind kind);

    Token peek_next_token();

    Token take_token();

    std::vector<Token> read_token_sequence(std::vector<TokenKind> expectedTokenKinds, bool eatEnd = true);

private:
    std::vector<Token> tokens;
    int read_pos = 0;
    std::stack<ScopeInformation> scopes;
};
