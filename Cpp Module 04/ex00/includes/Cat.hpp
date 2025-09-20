#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &obj);
		Cat(const std::string &new_Type);
		Cat &operator=(const Cat &obj);
		~Cat();
		void makeSound()const;
};

#endif