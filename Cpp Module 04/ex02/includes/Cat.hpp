#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &obj);
		Cat(const std::string &new_Type);
		Cat &operator=(const Cat &obj);
		~Cat();
		void makeSound()const;
};

#endif