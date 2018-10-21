#include "function.h"

#include <iostream>

void getLine(std::string & inStr)
{
    char temp[31];
    std::cin.get(temp, 30, '\n');
    std::cin.ignore(30, '\n');
    inStr = temp;
}

char getChar()
{
    char ch = std::cin.get();
    std::cin.ignore(80, '\n');
    return ch;
}
