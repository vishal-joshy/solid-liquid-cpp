#include <iostream>
#include <vector>
#include <string>

#include "Lexer.h"

bool isNumber(char c)
{
    return std::isdigit(static_cast<unsigned char>(c));
}

Lexer::Lexer(std::string str)
{
    this->str = str;
}

std::vector<Token> Lexer::Analyze()
{
    std::vector<Token> tokens;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            continue;

        Token temp;
        switch (str[i])
        {
        case '+':
            temp.tok = TokenType::PLUS;
            break;
        case '-':
            temp.tok = TokenType::MINUS;
            break;
        case '*':
            temp.tok = TokenType::MULT;
            break;
        case '/':
            temp.tok = TokenType::DIV;
            break;

        default:
            if (isNumber(str[i]))
            {
                std::string tempNumber = std::string(1, str[i]);
                i++;

                while (i < str.length() && isNumber(str[i]))
                {
                    tempNumber = tempNumber + str[i];
                    i++;
                }
                i--;
                temp.tok = TokenType::DOUBLE;
                temp.DoubleValue = std::stod(tempNumber);
            }
            else
            {
                throw "Invalid token";
            }
        }
        tokens.push_back(temp);
    }
    return tokens;
}
