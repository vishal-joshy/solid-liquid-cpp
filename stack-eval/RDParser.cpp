#include "RDParser.h"
#include "Lexer.h"

TokenGenerator::TokenGenerator(std::vector<Token> tokens)
{
    this->tokens = tokens;
    this->index = 0;
}

bool TokenGenerator::hasMore()
{
    return index < tokens.size();
}

Token TokenGenerator::yield()
{
    if (hasMore())
    {
        Token result = tokens[index];
        index = index + 1;
        return result;
    }
    else
    {
        Token result;
        result.tok = TokenType::TOK_NULL;
        return result;
    }
}

RDParser::RDParser(std::vector<Token> tokens)
{
    this->generator = new TokenGenerator(tokens);
}

double RDParser::doParse()
{
    currentToken = generator->yield();
    Expr();
    return stack.top();
}

void RDParser::Expr()
{
    Term();
    if (currentToken.tok == TokenType::PLUS || currentToken.tok == TokenType::MINUS)
    {
        Token op = currentToken;
        currentToken = generator->yield();
        Expr();
        double y = stack.top();
        stack.pop();
        double x = stack.top();
        stack.pop();
        if (op.tok == TokenType::PLUS)
        {
            stack.push(x + y);
        }
        else
        {
            stack.push(x - y);
        }
    }
}

void RDParser::Term()
{
    Factor();
    if (currentToken.tok == TokenType::MULT || currentToken.tok == TokenType::DIV)
    {
        Token op = currentToken;
        currentToken = generator->yield();
        Term();
        double y = stack.top();
        stack.pop();
        double x = stack.top();
        stack.pop();
        if (op.tok == TokenType::MULT)
        {
            stack.push(x * y);
        }
        else
        {
            stack.push(x / y);
        }
    }
}

void RDParser::Factor()
{
    if (currentToken.tok == TokenType::DOUBLE)
    {
        Token t = currentToken;
        currentToken = generator->yield();
        stack.push(t.DoubleValue);
    }
    else
    {
        throw "Invalid token";
    }
}