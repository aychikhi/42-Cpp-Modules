#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constractor called!" << std::endl;
	type = "LMDAHSSESS";
}

Animal::Animal(const std::string new_Type)
{
	std::cout << "Animal parameterized constractor called!" << std::endl;
	type = new_Type;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constractor called!" << std::endl;
	type = obj.type;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Animal copy assignment called!" << std::endl;
	type = obj.type;
	return *this;
}

void Animal::makeSound()const
{
	std::cout << "This animal doesn't make any sound!" << std::endl;
}

std::string Animal::getType()const
{
	return type;
}

Animal::~Animal()
{
	std::cout << "Animal cestractor called!" << std::endl;
}