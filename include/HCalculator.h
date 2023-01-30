#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "TStack.h"
#include <string>

class Calculator
{
    static int Priority(char);
public:
    static bool NoMistakes(std::string);
    static std::string Postfix(std::string);
    static void GettingValues(std::string, char*&, double*&, int&);
    static double Calculate(std::string, char*, double*, int);
};

#endif
