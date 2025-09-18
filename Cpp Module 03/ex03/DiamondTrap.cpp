#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called!" << std::endl;
	Energy_points = 50;
}

DiamondTrap::DiamondTrap(std::string new_Name) : ClapTrap(new_Name + "_clap_name"), ScavTrap(new_Name), FragTrap(new_Name)
{
	Energy_points = 50;
	Name = new_Name;
	std::cout << "DiamondTrap parametrized constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	ClapTrap::operator=(obj);
	std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << Name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}