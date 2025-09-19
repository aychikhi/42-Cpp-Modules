#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called!" << std::endl;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string new_Name) : ClapTrap(new_Name)
{
	std::cout << "ScavTrap parametrized constructor called!" << std::endl;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	ClapTrap::operator=(obj);
	std::cout << "ScavTrap copy assignment operator called!" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (Hit_points && Energy_points)
	{
		std::cout << "ScavTrap " << Name << " attacks " << target << ", causing "
			<< Attack_damage << " points of damage!" << std::endl;
		Energy_points--;
	}
	else
        std::cout << "ScavTrap " << Name << " can't attack because it has no hit points or energy points left!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << Name << " is the guardGate!" << std::endl;
}