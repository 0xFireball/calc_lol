
#pragma once

#include <vector>

#include "../lexer/Token.h"

class Parser {
public:
  Parser(std::vector<Token> tokens);
  
private:
  std::vector<Token> tokens;
};
