#include <iostream>
#include <vector>
#include <stack>
#include <memory>

#include "Expression.h"
#include "Lexer.h"
#include "RDParser.h"

void showHelp(){
    std::cout << "Usage : <filename> <expression>";
}

int main(int argc, char* argv[])
{
    if(argc < 2){
        showHelp();
        return -1;
    }

    Lexer lex(argv[1]);
    std::vector<Token> tokens = lex.Analyze();
    std::unique_ptr<RDParser> parser(new RDParser(tokens));
    double result = parser->doParse();
    std::cout << result;
    return 0;
}