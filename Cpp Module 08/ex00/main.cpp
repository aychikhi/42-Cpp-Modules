#include "easyfind.hpp"
#include <vector>    
#include <list>       
#include <deque>
#include <iostream>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    
    try {
        std::vector<int>::iterator i = easyfind(vec, 2);
        std::cout << "Vector: Found " << *i << std::endl;
    } catch (std::exception &e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }
    
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    
    try {
        std::list<int>::iterator i = easyfind(lst, 20);
        std::cout << "List: Found " << *i << std::endl;
    } catch (std::exception &e) {
        std::cout << "List: " << e.what() << std::endl;
    }
    
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    
    try {
        easyfind(deq, 999);
    } catch (std::exception &e) {
        std::cout << "Deque: " << e.what() << std::endl;
    }
    
    return 0;
}