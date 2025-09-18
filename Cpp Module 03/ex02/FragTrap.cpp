#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called!" << std::endl;
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
}

FragTrap::FragTrap(std::string new_Name) : ClapTrap(new_Name)
{
	std::cout << "FragTrap parametrized constructor called!" << std::endl;
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "FragTrap copy assignment operator called!" << std::endl;
	if (this != &obj)
	{
		Name = obj.Name;
		Hit_points = obj.Hit_points;
		Energy_points = obj.Energy_points;
		Attack_damage = obj.Attack_damage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (Hit_points && Energy_points)
	{
		std::cout << "FragTrap " << Name << " attacks " << target << ", causing "
			<< Attack_damage << " points of damage!" << std::endl;
		Energy_points--;
	}
	else
        std::cout << "FragTrap " << Name << " can't attack because it has no hit points or energy points left!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap: " << Name << " wanna a high five ?" << std::endl;
}