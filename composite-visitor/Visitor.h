#pragma once

#include <stack>

#include "Expression.h"

class NumericExp;
class BinaryExp;

class IVisitor
{
public:
    virtual double visit(NumericExp *num) = 0;
    virtual double visit(BinaryExp *bin) = 0;
};

class TreeEvaluator : public IVisitor
{
public:
    double visit(NumericExp *num);
    double visit(BinaryExp *bin);
};

class StackEvaluator : public IVisitor
{
private:
    std::stack<double> evalStack;

public:
    double visit(NumericExp *num);
    double visit(BinaryExp *bin);
    double getValue();
};