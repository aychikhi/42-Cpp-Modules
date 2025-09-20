#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string new_Name);
		FragTrap(const FragTrap &obj);
		FragTrap &operator=(const FragTrap &obj);
		~FragTrap();
		void highFivesGuys(void);
};

#endif