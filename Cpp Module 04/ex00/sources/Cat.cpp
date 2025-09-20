#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat constructor called!" << std::endl;
}

Cat::Cat(const std::string &new_Type) : Animal(new_Type)
{
	std::cout << "Cat parameterized constructor called!" << std::endl;
	type = new_Type;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	type = obj.type;
}

Cat &Cat::operator=(const Cat &obj) 
{
	std::cout << "Cat copy assignment called!" << std::endl;
	Animal::operator=(obj);
	return *this;
}

void Cat::makeSound()const
{
	std::cout << "MEOW!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}