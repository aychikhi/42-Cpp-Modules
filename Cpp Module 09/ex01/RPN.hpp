#pragma once 

#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<double> stack;
    public:
        RPN();
        RPN(const RPN &obj);
        RPN& operator=(const RPN& obj);
        ~RPN();
        void eval(const std::string& arg);
};