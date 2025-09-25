#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

struct Node
{
	AMateria *m;
	Node *next;
};

class Character : public ICharacter
{
	private:
		std::string Name;
		AMateria *slots[4];

		Node *Node;
		void addback(AMateria *m);
		void delete_all();

	public:
		Character();
		Character(const std::string &Name);
		Character(const Character &obj);
		Character &operator=(const Character &obj);
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif