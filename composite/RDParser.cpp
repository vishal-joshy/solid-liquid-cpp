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

Expression *RDParser::doParse()
{
    currentToken = generator->yield();
    return Expr();
}

Expression *RDParser::Expr()
{
    Expression *returnVal = Term();
    if (currentToken.tok == TokenType::PLUS || currentToken.tok == TokenType::MINUS)
    {
        Token op = currentToken;
        currentToken = generator->yield();
        Expression *exp = Expr();
        if (op.tok == TokenType::PLUS)
        {
            return new BinaryExp(arithmeticOperator::PLUS, returnVal, exp);
        }
        else
        {
            return new BinaryExp(arithmeticOperator::MINUS, returnVal, exp);
        }
    }
    return returnVal;
}

Expression *RDParser::Term()
{
    Expression *returnVal = Factor();
    if (currentToken.tok == TokenType::MULT || currentToken.tok == TokenType::DIV)
    {
        Token op = currentToken;
        currentToken = generator->yield();
        Expression *exp = Term();
        if (op.tok == TokenType::MULT)
        {
            return new BinaryExp(arithmeticOperator::MULT, returnVal, exp);
        }
        else
        {
            return new BinaryExp(arithmeticOperator::DIV, returnVal, exp);
        }
    }
    return returnVal;
}

Expression *RDParser::Factor()
{
    if (currentToken.tok == TokenType::DOUBLE)
    {
        Token temp = currentToken;
        currentToken = generator->yield();
        return new NumericExp(temp.DoubleValue);
    }
    else
    {
        throw "Invalid token";
    }
}