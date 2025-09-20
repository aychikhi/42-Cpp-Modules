#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called!" << std::endl;
}

WrongCat::WrongCat(const std::string &new_Type) : WrongAnimal(new_Type)
{
	std::cout << "WrongCat parameterized constructor called!" << std::endl;
	type = new_Type;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
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
	std::cout << "WrongCat destructor called!" << std::endl;
}