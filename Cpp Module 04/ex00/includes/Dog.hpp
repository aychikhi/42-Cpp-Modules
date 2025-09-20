#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &obj);
		Dog(const std::string &new_Type);
		Dog &operator=(const Dog &obj);
		~Dog();
		void makeSound()const;
};

#endif