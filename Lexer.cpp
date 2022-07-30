#include <iostream>
#include "Lexer.h"

Lexer::Lexer(std::string str)
{
    this->str = str;
    this->index = str.length();
}
