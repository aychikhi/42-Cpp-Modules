#include "Span.hpp"

int main()
{
    std::cout << "=== Subject's Mandatory Example ===" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
    {
        Span sp(10000);
        srand(time(NULL));
        for (int i = 0; i < 10000; i++) {
            sp.addNumber(rand());
        }
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test with range of iterators ===" << std::endl;
    {
        Span sp(10000);
        std::vector<int> vec(10000);
        for (int i = 0; i < 10000; i++) {
            vec[i] = i;
        }
        sp.addRange(vec.begin(), vec.end());
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Exception tests ===" << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); 
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}