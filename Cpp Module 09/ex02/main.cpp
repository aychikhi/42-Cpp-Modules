#include "PmergeMe.hpp"
#include <iostream> 
#include <stdexcept>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe obj;
        obj.parse(ac, av);
        obj.sort();
    }
    catch (std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}