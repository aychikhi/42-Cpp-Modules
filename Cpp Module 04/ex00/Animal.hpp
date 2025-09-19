#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &obj);
		Animal(const std::string new_Type);
		Animal &operator=(const Animal &obj);
		~Animal();
		void makeSound()const;
		std::string getType()const;
};

#endif