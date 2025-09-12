#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}
void HumanB::attack()
{
	std::cout << name << " attack with their " << weapon->getType() << std::endl;
}