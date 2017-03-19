
#include <string>
#include <algorithm>
#include "Parser.h"
#include "ast/VariableAssignmentNode.h"
#include "ast/VariableDeclarationNode.h"
#include "ast/FunctionDeclarationNode.h"
#include "ast/ReturnStatementNode.h"
#include "ast/IfStatementNode.h"
#include "ast/WhileLoopNode.h"

Parser::Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {

}

std::unique_ptr<ProgramNode> Parser::parse_to_ast() {
    std::unique_ptr<ProgramNode> programNode = std::make_unique<ProgramNode>();
    auto programNodeInst = programNode.get(); // to keep a variable for debugging
    scopes.push(ScopeInformation(nullptr, programNode.get()));
    std::stack<symbolmap_t> symbol_map_stack;

    while (!at_program_end()) {
        Token upcomingToken = peek_next_token();
        switch (upcomingToken.get_kind()) {
            case TokenKind::KEYWORD: {
                Token keyword = take_token();
                bool atGlobalScope = scopes.size() == 1;
                // TODO
                if (keyword_is_type_keyword(keyword.get_content())) {
                    // type keyword:
                    // if in global scope, could be a function, otherwise a var declaration

                    std::string keyword_type = keyword.get_content();
                    Token name_tok = read_expected_token(TokenKind::IDENTIFIER);
                    Token lookahead = peek_next_token();
                    // if the lookahead is an assignment operator, a variable declaration
                    if ((lookahead.get_kind() == TokenKind::OPERATOR && lookahead.get_content() == "=") ||
                        (lookahead.get_kind() == TokenKind::STMT_SEP)) {
                        if (lookahead.get_kind() == TokenKind::OPERATOR) {
                            // eat the assignment operator
                            take_token();
                            std::vector<Token> valueExpression = read_until_statement_end();
                            std::unique_ptr<ExpressionNode> value_expr_tree = ExpressionNode::create_from_tokens(
                                    valueExpression, this);
                            peek_scope_statements()->append_new_statement<VariableDeclarationNode>(
                                    name_tok.get_content(),
                                    std::move(value_expr_tree));
                        } else {
                            peek_scope_statements()->append_new_statement<VariableDeclarationNode>(
                                    name_tok.get_content());
                        }
                        // register symbol
                        peek_scope_info()->symbol_map[name_tok.get_content()] = std::shared_ptr<SymbolInformation>(
                                new SymbolInformation((int) scopes.size(),
                                                      SymbolKind::VARIABLE,
                                                      keyword_type));
                    } else if (atGlobalScope && (lookahead.get_kind() == TokenKind::ROUND_BRACE)) {
                        // A function declaration
                        FunctionDeclarationNode *func = peek_scope_statements()->append_new_statement<FunctionDeclarationNode>(
                                name_tok.get_content(),
                                keyword_type); // add the function to the old scope (with return type!)...
                        scopes.push(ScopeInformation(peek_scope_info(), func)); // ..and set that as the new scope!
                        take_token(); // eat open brace (lookahead)
                        while (peek_next_token().get_kind() != TokenKind::CLOSE_ROUND_BRACE) {
                            Token arg_type = read_expected_token(TokenKind::KEYWORD);
                            if (!keyword_is_type_keyword(arg_type.get_content())) {
                                throw ParseError("Expected type keyword.");
                            }
                            Token arg_name = read_expected_token(TokenKind::IDENTIFIER);
                            // register parameter
                            func->add_parameter(
                                    ParameterDeclarationNode(arg_type.get_content(), arg_name.get_content()));
                            if (peek_next_token().get_kind() == TokenKind::ARG_SEP) {
                                take_token(); // eat the arg separator and loop
                            }
                            // register parameter symbol
                            peek_scope_info()->symbol_map[arg_name.get_content()] = std::shared_ptr<SymbolInformation>(
                                    new SymbolInformation((int) scopes.size(),
                                                          SymbolKind::VARIABLE,
                                                          arg_type.get_content()));
                        }
                        // eat the closing brace
                        take_token();
                        Token body_open = read_expected_token(TokenKind::CURLY_BRACE);
                        // register symbol for function (with return type!)
                        peek_scope_info()->symbol_map[name_tok.get_content()] = std::shared_ptr<SymbolInformation>(
                                new SymbolInformation((int) scopes.size(),
                                                      SymbolKind::FUNCTION,
                                                      keyword_type));
                    }
                } else if (!atGlobalScope) { // control keywords are not valid on the global scope
                    // control keyword (eg. if, while, return)
                    std::string keyword_content = keyword.get_content();
                    // get expression
                    std::vector<Token> res_expr = read_until_statement_end();
                    std::unique_ptr<ExpressionNode> expr_tree = ExpressionNode::create_from_tokens(res_expr, this);
                    if (keyword_content == "return") {
                        peek_scope_statements()->append_new_statement<ReturnStatementNode>(std::move(expr_tree));
                    } else if (keyword_content == "if") {
                        IfStatementNode *if_st = peek_scope_statements()->append_new_statement<IfStatementNode>(
                                std::move(expr_tree));
                        // eat the opening brace
                        read_expected_token(TokenKind::CURLY_BRACE);
                    } else if (keyword_content == "while") {
                        WhileLoopNode *while_st = peek_scope_statements()->append_new_statement<WhileLoopNode>(
                                std::move(expr_tree));
                        // eat the opening brace
                        read_expected_token(TokenKind::CURLY_BRACE);
                    }
                }
                break;
            }
            case TokenKind::IDENTIFIER: {
                Token identifier = take_token();
                Token nextToken = peek_next_token();
                if (nextToken.get_kind() == TokenKind::OPERATOR && nextToken.get_content() == "=") {
                    // assignment operator
                    take_token(); // eat the assignment operator
                    // make sure the identifier is an existing symbol
                    if (symbol_exists(identifier.get_content(), SymbolKind::VARIABLE)) {
                        // the variable that they tried to assign did not exist
                        throw CompilationError("Could not resolve symbol: " + identifier.get_content());
                    }
                    std::vector<Token> valueExpression = read_until_statement_end();
                    std::unique_ptr<ExpressionNode> value_expr_tree = ExpressionNode::create_from_tokens(
                            valueExpression, this);
                    peek_scope_statements()->append_new_statement<VariableAssignmentNode>(identifier.get_content(),
                                                                                          std::move(value_expr_tree));
                }
                break;
            }
            case TokenKind::CLOSE_CURLY_BRACE: {
                // scope end
                take_token(); // eat the brace
                scopes.pop(); // pop off the previous scope
                break;
            }
            default:
                throw UnexpectedTokenException("The parser encountered an unexpected token");
        }
    }

    scopes.pop();
    return programNode;
}

StatementSequenceNode *Parser::peek_scope_statements() {
    return scopes.top().statements;
}

ScopeInformation *Parser::peek_scope_info() {
    return &scopes.top();
}

bool Parser::at_program_end() {
    return read_pos >= tokens.size();
}

Token Parser::take_token() {
    Token ret = peek_next_token();
    ++read_pos;
    return ret;
}

Token Parser::peek_next_token() {
    return tokens[read_pos];
}

Token Parser::read_expected_token(TokenKind kind) {
    Token upcomingToken = peek_next_token();
    TokenKind t_kind = upcomingToken.get_kind();
    if (t_kind == kind) {
        // valid, advance and return
        return take_token();
    } else {
        throw UnexpectedTokenException("Unexpected token: " + std::to_string((int) t_kind));
    }
}

std::vector<Token> Parser::read_until_token(TokenKind endKind, bool eatEnd) {
    std::vector<Token> read_tokens;
    Token upcomingToken = peek_next_token();
    while (!at_program_end() && upcomingToken.get_kind() != endKind) {
        read_tokens.push_back(take_token());
        upcomingToken = peek_next_token();
    }
    if (eatEnd) {
        take_token(); // eat the end 
    }
    return read_tokens;
}

std::vector<Token> Parser::read_token_sequence(std::vector<TokenKind> expectedTokenKinds, bool eatEnd) {
    std::vector<Token> read_tokens;
    Token upcomingToken = peek_next_token();
    while (!at_program_end() &&
           std::find(std::begin(expectedTokenKinds), std::end(expectedTokenKinds), upcomingToken.get_kind()) !=
           std::end(expectedTokenKinds)) {
        read_tokens.push_back(take_token());
        upcomingToken = peek_next_token();
    }
    if (eatEnd) {
        take_token(); // eat the end 
    }
    return read_tokens;
}

std::vector<Token> Parser::read_until_statement_end() {
    return read_until_token(TokenKind::STMT_SEP, true);
}

std::shared_ptr<SymbolInformation>
Parser::resolve_symbol_in_scope(std::string identifier, ScopeInformation *scope_info) {
    if (scope_info == nullptr) return nullptr;

    auto iter = scope_info->symbol_map.find(identifier);
    if (iter == scope_info->symbol_map.end())
        return resolve_symbol_in_scope(identifier, scope_info->parent_scope);
    return iter->second;
}

bool Parser::symbol_exists(std::string identifier, SymbolKind kind) {
    std::shared_ptr<SymbolInformation> symbol_info = resolve_symbol(identifier);
    if (symbol_info == nullptr) return false;
    return symbol_info->kind == kind;
}

std::shared_ptr<SymbolInformation> Parser::resolve_symbol(std::string identifier) {
    return resolve_symbol_in_scope(identifier, peek_scope_info());
}
