#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;	
}

Ice::Ice(const Ice &obj) : AMateria(obj)
{
	std::cout << "Ice copy constructor called" << std::endl;	
}

Ice &Ice::operator=(const Ice &obj)
{
	std::cout << "Ice copy assignment called" << std::endl;
	AMateria::operator=(obj);
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone()const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}