#pragma once

#include <iostream>
#include <vector>

enum class TokenType
{
    PLUS,
    MINUS,
    DIV,
    MULT,
    DOUBLE,
    ILLEGAL,
    TOK_NULL
};

struct Token
{
    TokenType tok;
    double DoubleValue;
};

class Lexer
{
private:
    std::string str;

public:
    Lexer(std::string str);
    std::vector<Token> Analyze();
};
