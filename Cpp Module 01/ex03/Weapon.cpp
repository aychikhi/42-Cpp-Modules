#include "Weapon.hpp"

const std::string &Weapon::getType(void)
{
	return type;
}

void Weapon::setType(std::string newType)
{
	type = newType;
}
Weapon::Weapon(std::string type)
{
	this->type = type;
}