#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;	
}

Cure::Cure(const Cure &obj) : AMateria(obj)
{
	std::cout << "Cure copy constructor called" << std::endl;	
}

Cure &Cure::operator=(const Cure &obj)
{
	std::cout << "Cure copy assignment called" << std::endl;
	AMateria::operator=(obj);
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone()const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}