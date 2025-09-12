#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weopon &weopon;
		std::string name;
	public:
		HumanA(Weopon &new_weopon)
		void attack(void);
};

#endif
