#include "Visitor.h"
#include "Expression.h"

Item FlattenVisitor::makeList(double number)
{
    Item result;
    result.value = number;
    result.kind = ExprKind::Value;
    return result;
}

Item FlattenVisitor::makeList(arithmeticOperator op)
{
    Item result;
    result.op = op;
    result.kind = ExprKind::Operator;
    return result;
}

std::vector<Item> FlattenVisitor::flattenedExp()
{
    return this->list;
}

double FlattenVisitor::visit(NumericExp *num)
{
    this->list.push_back(makeList(num->getNumber()));
    return 0;
}

double FlattenVisitor::visit(BinaryExp *bin)
{
    bin->getLExp()->accept(this);
    bin->getRExp()->accept(this);
    this->list.push_back(makeList(bin->getOperator()));
    return 0;
}
