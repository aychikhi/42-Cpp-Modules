#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat constractor called!" << std::endl;
}

WrongCat::WrongCat(const std::string new_Type) : WrongAnimal(new_Type)
{
	std::cout << "WrongCat parameterized constractor called!" << std::endl;
	type = new_Type;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat copy constractor called!" << std::endl;
	type = obj.type;
}

WrongCat &WrongCat::operator=(const WrongCat &obj) 
{
	std::cout << "WrongCat copy assignment called!" << std::endl;
	WrongAnimal::operator=(obj);
	return *this;
}

void WrongCat::makeSound()const
{
	std::cout << "MEOW!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destractor called!" << std::endl;
}