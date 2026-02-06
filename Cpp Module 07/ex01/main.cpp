#include "iter.hpp"
#include <iostream>

template <typename T>
void print(const T& x)
{
    std::cout << x << std::endl;
}

void increment(int& x)
{
    x++;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    
    std::cout << "Original array:" << std::endl;
    iter(intArray, 5, print<int>);
    
    std::cout << "\nAfter increment:" << std::endl;
    iter(intArray, 5, increment);
    iter(intArray, 5, print<int>);
    
    std::string strArray[] = {"Hello", "World", "42"};
    
    std::cout << "\nString array:" << std::endl;
    iter(strArray, 3, print<std::string>);
    
    return 0;
}