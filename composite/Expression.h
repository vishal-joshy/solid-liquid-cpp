#pragma once

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
    virtual double Evaluate() = 0;
};

class NumericExp : public Expression
{
private:
    double num;

public:
    NumericExp(double num);
    double Evaluate();
};

class BinaryExp : public Expression
{
private:
    arithmeticOperator op;
    Expression *exp1, *exp2;

public:
    BinaryExp(arithmeticOperator op, Expression *exp1, Expression *exp2);
    double Evaluate();
    NumericExp getExp();
};
