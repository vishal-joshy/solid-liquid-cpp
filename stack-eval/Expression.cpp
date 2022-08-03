#include "Expression.h"

NumericExp::NumericExp(double num)
{
    this->num = num;
}

double NumericExp::Evaluate()
{
    return this->num;
}

BinaryExp::BinaryExp(arithmeticOperator op, Expression *exp1, Expression *exp2)
{
    this->op = op;
    this->exp1 = exp1;
    this->exp2 = exp2;
}

double BinaryExp::Evaluate()
{
    double n1 = this->exp1->Evaluate();
    double n2 = this->exp2->Evaluate();

    switch (this->op)
    {
    case arithmeticOperator::PLUS:
        return n1 + n2;
    case arithmeticOperator::MINUS:
        return n1 - n2;
    case arithmeticOperator::MULT:
        return n1 * n2;
    case arithmeticOperator::DIV:
        return n1 / n2;
    default:
        throw "Invalid Binary operation";
    }
}