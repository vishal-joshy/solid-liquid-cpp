#include <iostream>
#include <vector>
#include <stack>

#include "Expression.h"
#include "Visitor.h"
#include "Lexer.h"
#include "RDParser.h"

std::vector<Item> FlattenExpressionToList(Expression *exp)
{
    FlattenVisitor *fv = new FlattenVisitor();
    exp->accept(fv);
    return fv->flattenedExp();
}

template <class T>
class IObserver
{
public:
    void onNext(T item)
    {
        std::cout << item.ExprKind;
    }
    void onCompleted(double result)
    {
        std::cout << result;
    }
};

template <class T>
class Observable : public IObserver<T>
{
private:
    std::vector<T> list;

public:
    Observable(std::vector<T> list)
    {
        this->list = list;
    }
    void Subscribe(IObserver<T> *i)
    {
        std::stack<double> EvalStack;

        for (auto &&i : list)
        {
            if (i.kind == ExprKind::Value)
            {
                EvalStack.push(i.value);
            }
            else
            {
                double x = EvalStack.top();
                EvalStack.pop();
                double y = EvalStack.top();
                EvalStack.pop();

                switch (i.op)
                {
                case arithmeticOperator::PLUS:
                    EvalStack.push(x + y);
                    break;
                case arithmeticOperator::MINUS:
                    EvalStack.push(x - y);
                    break;
                case arithmeticOperator::MULT:
                    EvalStack.push(x * y);
                    break;
                case arithmeticOperator::DIV:
                    EvalStack.push(x / y);
                    break;
                default:
                    throw "invalid operator";
                }
            }
        }

        std::cout << EvalStack.top();
    }
};

int main()
{
    Lexer lex("2+33*2");
    std::vector<Token> tokens = lex.Analyze();
    RDParser *parser = new RDParser(tokens);
    Expression *exp = parser->doParse();
    std::vector<Item> flattenedExp = FlattenExpressionToList(exp);

    Observable<Item> *observable = new Observable<Item>(flattenedExp);
    IObserver<Item> *observer = new IObserver<Item>();
    observable->Subscribe(observer);
}