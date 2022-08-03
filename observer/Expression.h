#pragma once
#include "Visitor.h"

class IVisitor;

enum class arithmeticOperator
{
    PLUS,
    MINUS,
    MULT,
    DIV
};

class Expression
{
public:
    virtual double accept(IVisitor *v) = 0;
};

class NumericExp : public Expression
{
private:
    double num;

public:
    NumericExp(double num);
    double getNumber();
    double accept(IVisitor *v);
};

class BinaryExp : public Expression
{
private:
    arithmeticOperator op;
    Expression *exp1, *exp2;

public:
    BinaryExp(arithmeticOperator op, Expression *exp1, Expression *exp2);
    Expression *getLExp();
    Expression *getRExp();
    arithmeticOperator getOperator();
    double accept(IVisitor *v);
};
