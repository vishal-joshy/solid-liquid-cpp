#include "Visitor.h"
#include "Expression.h"

double TreeEvaluator::visit(NumericExp *num)
{
    return num->getNumber();
}

double TreeEvaluator::visit(BinaryExp *bin)
{
    double eval1 = bin->getLExp()->accept(this);
    double eval2 = bin->getRExp()->accept(this);

    arithmeticOperator op = bin->getOperator();

    switch (op)
    {
    case arithmeticOperator::PLUS:
        return eval1 + eval2;
        break;
    case arithmeticOperator::MINUS:
        return eval1 - eval2;
        break;
    case arithmeticOperator::MULT:
        return eval1 * eval2;
        break;
    case arithmeticOperator::DIV:
        return eval1 / eval2;
        break;

    default:
        throw "invalid operator";
    }
}

double StackEvaluator::visit(NumericExp *num)
{
    this->evalStack.push(num->getNumber());
    return 0;
}

double StackEvaluator::getValue()
{
    return this->evalStack.top();
}

double StackEvaluator::visit(BinaryExp *bin)
{
    bin->getLExp()->accept(this);
    bin->getRExp()->accept(this);

    double lEval = evalStack.top();
    evalStack.pop();
    double rEval = evalStack.top();
    evalStack.pop();

    switch (bin->getOperator())
    {
    case arithmeticOperator::PLUS:
        evalStack.push(lEval + rEval);
        break;
    case arithmeticOperator::MINUS:
        evalStack.push(lEval - rEval);
        break;
    case arithmeticOperator::MULT:
        evalStack.push(lEval * rEval);
        break;
    case arithmeticOperator::DIV:
        evalStack.push(lEval / rEval);
        break;
    }
    return 0;
}
