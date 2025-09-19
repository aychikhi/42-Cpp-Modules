#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called!" << std::endl;
	type = "LMDAHSSESS";
}

WrongAnimal::WrongAnimal(const std::string new_Type)
{
	std::cout << "WrongAnimal parameterized constructor called!" << std::endl;
	type = new_Type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	type = obj.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal copy assignment called!" << std::endl;
	type = obj.type;
	return *this;
}

void WrongAnimal::makeSound()const
{
	std::cout << "This Wronganimal doesn't make any sound!" << std::endl;
}

std::string WrongAnimal::getType()const
{
	return type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destractor called!" << std::endl;
}