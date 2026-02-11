#include "Span.hpp"

Span::Span() : max(0), n()
{}

Span::Span(unsigned int n) : max(n)
{
    this->n.reserve(n);
}

Span::Span(const Span& other)
{
    this->max = other.max;
    this->n = other.n;
}

Span &Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->max = other.max;
        this->n = other.n;
    }
    return *this;
}

Span::~Span()
{
}
void Span::addNumber(int num)
{
    if(n.size() >= max)
        throw std::runtime_error("Span is full");
    n.push_back(num);
}


int Span::shortestSpan() const
{
    if(n.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");

    std::vector<int> sorted = n;
    std::sort(sorted.begin(), sorted.end());
    int min = INT_MAX;
    for(size_t i = 1; i < sorted.size(); i++)
    {
        int span = sorted[i] - sorted[i - 1];
        if(span < min)
            min = span;
    }
    return min;
}

int Span::longestSpan() const
{
    if (n.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");
    int min = *std::min_element(n.begin(), n.end());
    int max = *std::max_element(n.begin(), n.end());
    return max - min;
}