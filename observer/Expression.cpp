#include "Expression.h"
#include "Visitor.h"

NumericExp::NumericExp(double num)
{
    this->num = num;
}

double NumericExp::getNumber()
{
    return this->num;
}

double NumericExp::accept(IVisitor *v)
{
    return v->visit(this);
}

BinaryExp::BinaryExp(arithmeticOperator op, Expression *exp1, Expression *exp2)
{
    this->op = op;
    this->exp1 = exp1;
    this->exp2 = exp2;
}

Expression *BinaryExp::getLExp()
{
    return this->exp1;
}

Expression *BinaryExp::getRExp()
{
    return this->exp2;
}

arithmeticOperator BinaryExp::getOperator()
{
    return this->op;
}

double BinaryExp::accept(IVisitor *v)
{
    return v->visit(this);
}
