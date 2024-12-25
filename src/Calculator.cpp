//
// Created by Nikita Lukyanovich on 25.12.24.
//

#include "Calculator.h"

RationalNumber Calculator::evaluate(const std::string &expression)
{
    auto postfix = infixToPostfix(expression);
    return evaluatePostfix(postfix);
}

bool Calculator::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

std::vector<std::string> Calculator::infixToPostfix(const std::string &expression) const
{
    std::stack<char> operators;
    std::vector<std::string> postfix;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isNumber(token)) {
            postfix.push_back(token);
        } else if (token == "(") {
            operators.push('(');
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != '(') {
                postfix.emplace_back(1, operators.top());
                operators.pop();
            }
            if (operators.empty())
                throw std::runtime_error("Mismatched parentheses");
            operators.pop(); // Pop the '('
        } else if (isOperator(token[0])) {
            while (!operators.empty()
                   && precedence.at(operators.top()) >= precedence.at(token[0])) {
                postfix.emplace_back(1, operators.top());
                operators.pop();
            }
            operators.push(token[0]);
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }

    while (!operators.empty()) {
        if (operators.top() == '(')
            throw std::runtime_error("Mismatched parentheses");
        postfix.emplace_back(1, operators.top());
        operators.pop();
    }

    return postfix;
}

RationalNumber Calculator::evaluatePostfix(const std::vector<std::string> &postfix)
{
    std::stack<RationalNumber> operands;

    for (const auto &token : postfix) {
        if (isNumber(token)) {
            operands.push(parseRationalNumber(token));
        } else if (isOperator(token[0])) {
            if (operands.size() < 2)
                throw std::runtime_error("Invalid postfix expression");

            auto right = operands.top();
            operands.pop();
            auto left = operands.top();
            operands.pop();

            switch (token[0]) {
            case '+':
                operands.push(left + right);
                break;
            case '-':
                operands.push(left - right);
                break;
            case '*':
                operands.push(left * right);
                break;
            case '/':
                operands.push(left / right);
                break;
            default:
                throw std::runtime_error("Unknown operator: " + token);
            }
        } else {
            throw std::runtime_error("Invalid token in postfix expression: " + token);
        }
    }

    if (operands.size() != 1)
        throw std::runtime_error("Invalid postfix expression");

    return operands.top();
}

bool Calculator::isNumber(const std::string &token)
{
    return !token.empty() && (std::isdigit(token[0]) || token[0] == '-');
}

RationalNumber Calculator::parseRationalNumber(const std::string &token)
{
    size_t slashPos = token.find('/');
    if (slashPos != std::string::npos) {
        int numerator = std::stoi(token.substr(0, slashPos));
        unsigned denominator = std::stoul(token.substr(slashPos + 1));
        return { numerator, denominator };
    }
    return { std::stoi(token), 1 };
}