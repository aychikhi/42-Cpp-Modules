#pragma once

#include <vector>
#include <iostream>  
#include <cstdlib>    
#include <algorithm>
#include <climits> 
#include <ctime> 

class Span
{
    private:
        unsigned int max;
        std::vector<int> n;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
        template<typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            for(Iterator i = begin; i != end; i++)
                addNumber(*i);
        }
};