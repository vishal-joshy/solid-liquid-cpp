#pragma once

#include <stack>
#include <vector>

#include "Expression.h"

class NumericExp;
class BinaryExp;
enum class arithmeticOperator;

enum class ExprKind
{
    Operator,
    Value
};

struct Item
{
    arithmeticOperator op;
    double value;
    ExprKind kind;
};


class IVisitor
{
public:
    virtual double visit(NumericExp *num) = 0;
    virtual double visit(BinaryExp *bin) = 0;
};

class FlattenVisitor:public IVisitor
{
private:
    std::vector<Item> list;

public:
    Item makeList(double number);
    Item makeList(arithmeticOperator op);
    double visit(NumericExp *num);
    double visit(BinaryExp *bin);
    std::vector<Item> flattenedExp();
};
