#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

MateriaSource::MateriaSource(AMateria *slots[4])
{
	std::cout << "MateriaSource parameterized constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slots[i])
		{
			this->slots[i] = slots[i]->clone();
		}
		else
			this->slots[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = obj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	std::cout << "MateriaSource copy assignment called" << std::endl;	
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			if (slots[i])
				delete slots[i];
			slots[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (obj.slots[i])
				slots[i] = obj.slots[i]->clone();
			else
				slots[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete slots[i];
		slots[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		std::cout << "cannot learn a NULL Materia" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!slots[i])
		{
			slots[i] = m->clone();
			return;
		}
	}
	std::cout << "this Materia is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
	{
		if (slots[i] && slots[i]->getType() == type)
		{
			return slots[i]->clone();
		}
	}
	std::cout << "type not found" << std::endl;
	return NULL;
}