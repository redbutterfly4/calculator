#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <cctype>

#include "RationalNumber.h"

class Calculator
{
public:
    RationalNumber evaluate(const std::string &expression);

private:
    const std::unordered_map<char, int> precedence = {
        { '+', 1 }, { '-', 1 }, { '*', 2 }, { '/', 2 }, { '(', 0 }
    };

    [[nodiscard]] static bool isOperator(char c);

    [[nodiscard]] std::vector<std::string> infixToPostfix(const std::string &expression) const;

    [[nodiscard]] static RationalNumber evaluatePostfix(const std::vector<std::string> &postfix);

    static bool isNumber(const std::string &token);

    [[nodiscard]] static RationalNumber parseRationalNumber(const std::string &token);
};

#endif // CALCULATOR_H
