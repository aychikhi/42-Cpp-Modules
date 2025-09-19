#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constractor called!" << std::endl;
	type = "LMDAHSSESS";
}

WrongAnimal::WrongAnimal(const std::string new_Type)
{
	std::cout << "WrongAnimal parameterized constractor called!" << std::endl;
	type = new_Type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal copy constractor called!" << std::endl;
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

std::string WrongAnimal::getType()
{
	return type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal cestractor called!" << std::endl;
}