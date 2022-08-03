#include <vector>
#include <iostream>
#include <stack>

#include "Lexer.h"

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
    void Expr();
    void Term();
    void Factor();

public:
    RDParser(std::vector<Token> tokens);
    double doParse();
};
