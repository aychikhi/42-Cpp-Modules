#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    Array<int> arr(5);
    
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i;

    Array<int> copy(arr);
    copy[0] = 42;
    std::cout << "Original: " << arr[0] << ", Copy: " << copy[0] << std::endl;

    Array<int> assigned = arr;
    assigned[0] = 99;
    std::cout << "Original: " << arr[0] << ", Assigned: " << assigned[0] << std::endl;

    try {
        arr[10] = 0;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught" << std::endl;
    }

    return 0;
}
