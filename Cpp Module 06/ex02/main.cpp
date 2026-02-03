#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    srand(time(NULL));
    
    std::cout << "=== Testing identify() functions ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Test 1 - Using pointer:" << std::endl;
    Base* obj1 = generate();
    identify(obj1);
    delete obj1;
    
    std::cout << std::endl;
    
    std::cout << "Test 2 - Using reference:" << std::endl;
    Base* obj2 = generate();
    identify(*obj2);
    delete obj2;
    
    std::cout << std::endl;
    
    std::cout << "Test 3 - Multiple random objects:" << std::endl;
    for (int i = 0; i < 6; i++)
    {
        Base* obj = generate();
        std::cout << "Object " << i + 1 << " - ";
        std::cout << "Pointer: ";
        identify(obj);
        std::cout << "           Reference: ";
        identify(*obj);
        delete obj;
    }
    
    return 0;
}