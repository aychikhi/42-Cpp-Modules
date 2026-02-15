#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& obj) : stack(obj.stack) {}

RPN& RPN::operator=(const RPN& obj)
{
    if(this != &obj)
        stack = obj.stack;
    return *this;
}

RPN::~RPN() {}

void RPN::eval(const std::string& arg)
{
    std::istringstream iss(arg);
    std::string token;

    while(iss >> token)
    {
        if(token == "+" || token == "-" || token == "*" || token == "/")
        {
            if(stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            if (token == "+") 
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return;
                }
                stack.push(a / b);
            }
        }
        else if (token.length() == 1 && std::isdigit(token[0]))
        {
            stack.push(token[0] - '0');
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }
    if(stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl;
}
