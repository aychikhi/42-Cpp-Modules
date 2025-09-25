#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called!" << std::endl;
}

Dog::Dog(const std::string &new_Type) : Animal(new_Type)
{
	std::cout << "Dog parameterized constructor called!" << std::endl;
	type = new_Type;
	brain = new Brain();
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	type = obj.type;
	brain = new Brain(*(obj.brain));
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &obj) 
{
	std::cout << "Dog copy assignment called!" << std::endl;
	Animal::operator=(obj);
	delete brain;
	brain = new Brain(*(obj.brain));
	return *this;
}

void Dog::makeSound()const
{
	std::cout << "BARK!" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called!" << std::endl;
}