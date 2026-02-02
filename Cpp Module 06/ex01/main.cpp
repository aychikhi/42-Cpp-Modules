#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data original;
    original.name = "slawy";
    original.age = 23;
    
    Data* originalPtr = &original;
    
    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Address: " << originalPtr << std::endl;
    std::cout << "Name: " << originalPtr->name << std::endl;
    std::cout << "Age: " << originalPtr->age << std::endl;
    
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "\n=== Serialized ===" << std::endl;
    std::cout << "Value: " << serialized << std::endl;
    
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "\n=== Deserialized ===" << std::endl;
    std::cout << "Address: " << deserializedPtr << std::endl;
    std::cout << "Name: " << deserializedPtr->name << std::endl;
    std::cout << "Age: " << deserializedPtr->age << std::endl;
    
    std::cout << "\n=== Verification ===" << std::endl;
    if (deserializedPtr == originalPtr)
        std::cout << "✓ Success! Pointers are equal!" << std::endl;
    else
        std::cout << "✗ Error! Pointers are different!" << std::endl;
    
    return 0;
}