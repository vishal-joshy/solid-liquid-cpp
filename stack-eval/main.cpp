#include <iostream>
#include <vector>
#include <stack>
#include <memory>

#include "Expression.h"
#include "Lexer.h"
#include "RDParser.h"

int main(int argc, char* argv[])
{
    Lexer lex(argv[1]);
    std::vector<Token> tokens = lex.Analyze();
    std::unique_ptr<RDParser> parser(new RDParser(tokens));
    double result = parser->doParse();
    std::cout << result;
    return 0;
}