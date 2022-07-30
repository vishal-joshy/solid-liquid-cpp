#include <iostream>
#include "Expression.h"
#include "Lexer.h"

int main()
{
    Expression *e1 = new NumericExp(2);
    Expression *e2 = new NumericExp(3);

    BinaryExp bin(arithmeticOperator::PLUS, e1, e2);
    std::cout << bin.Evaluate();
}