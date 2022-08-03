#include <vector>
#include <iostream>
#include <stack>

#include "Lexer.h"
#include "Expression.h"

class TokenGenerator
{
private:
    std::vector<Token> tokens;
    int index;
    bool hasMore();

public:
    TokenGenerator(std::vector<Token> tokens);
    Token yield();
};

class RDParser
{
private:
    TokenGenerator *generator;
    Token currentToken;
    std::stack<double> stack;
    Expression * Expr();
    Expression * Term();
    Expression * Factor();

public:
    RDParser(std::vector<Token> tokens);
    Expression* doParse();
};
