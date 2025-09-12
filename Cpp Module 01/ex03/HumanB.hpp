#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weopon *weopon;
		std::string name;
	public:
		HumanB(std::string name);
		void setWepon(Weopon *new_weopon);
		void attack(void);
};

#endif
