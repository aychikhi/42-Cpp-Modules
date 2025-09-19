#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constractor called!" << std::endl;
}

Dog::Dog(const std::string new_Type) : Animal(new_Type)
{
	std::cout << "Dog parameterized constractor called!" << std::endl;
	type = new_Type;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog copy constractor called!" << std::endl;
	type = obj.type;
}

Dog &Dog::operator=(const Dog &obj) 
{
	std::cout << "Dog copy assignment called!" << std::endl;
	Animal::operator=(obj);
	return *this;
}

void Dog::makeSound()const
{
	std::cout << "BARK!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog cestractor called!" << std::endl;
}