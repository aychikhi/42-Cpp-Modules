#include "../includes/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;	
	type = "default";
}
AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria parameterized constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &obj)
{
	std::cout << "AMateria copy constructor called" << std::endl;	
	this->type = obj.type;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	std::cout << "AMateria copy assignment called" << std::endl;	
	if (this != &obj)
	{
		this->type = obj.getType();
	}
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}