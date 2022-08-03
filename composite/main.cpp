#include <iostream>
#include <vector>
#include <stack>

#include "Expression.h"
#include "Lexer.h"
#include "RDParser.h"

int main(int argc, char *argv[])
{
    Lexer lex(argv[1]);
    std::vector<Token> tokens = lex.Analyze();
    RDParser *parser = new RDParser(tokens);
    Expression *result = parser->doParse();
    std::cout << result->Evaluate();
}