#include <iostream>

enum class TokenType
{
    PLUS,
    MINUS,
    DIV,
    MULT,
    DOUBLE,
    ILLEGAL
};

struct Token
{
    TokenType tok;
    int DoubleValue;
};

class Lexer
{
private:
    std::string str;
    int index;

public:
    Lexer(std::string str);
    Token GetToken();
};
