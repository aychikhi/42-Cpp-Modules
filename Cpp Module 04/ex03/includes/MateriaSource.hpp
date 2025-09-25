#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *slots[4];
	public:
		MateriaSource();
		MateriaSource(AMateria *slots[4]);
		MateriaSource(const MateriaSource &obj);
		MateriaSource &operator=(const MateriaSource &obj);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria*m);
		virtual AMateria* createMateria(std::string const & type);
};

#endif