#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called!" << std::endl;
}

Cat::Cat(const std::string &new_Type) : Animal(new_Type)
{
	std::cout << "Cat parameterized constructor called!" << std::endl;
	type = new_Type;
	brain = new Brain();
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	type = obj.type;
	brain = new Brain(*(obj.brain));
}

Cat &Cat::operator=(const Cat &obj) 
{
	std::cout << "Cat copy assignment called!" << std::endl;
	Animal::operator=(obj);
	delete brain;
	brain = new Brain(*(obj.brain));
	return *this;
}

void Cat::makeSound()const
{
	std::cout << "MEOW!" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called!" << std::endl;
}