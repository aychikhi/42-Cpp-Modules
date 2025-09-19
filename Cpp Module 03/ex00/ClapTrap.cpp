#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called!" << std::endl;
	Name = "LMRAYTET";
	Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
}

ClapTrap::ClapTrap(std::string new_name)
{
	std::cout << "Parametrized constructor called!" << std::endl;
	Name = new_name;
	Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor called!" << std::endl;
    *this = obj;
}

void ClapTrap::attack(const std::string& target)
{
	if (Hit_points && Energy_points)
	{
		std::cout << "ClapTrap " << Name << " attacks " << target << ", causing "
			<< Attack_damage << " points of damage!" << std::endl;
		Energy_points--;
		std::cout << "ClapTrap " << Name << " now has " << Energy_points << " energy points left." << std::endl;
	}
	else
        std::cout << "ClapTrap " << Name << " can't attack because it has no hit points or energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount == 0) 
	{
        std::cout << "No damage dealt to ClapTrap " << Name << std::endl;
        return;
    }
	if (Hit_points > 0)
	{
		std::cout << "ClapTrap " << Name << " was attacked, causing " << amount << " points of damage!"
			<< std::endl;
		if (Hit_points > (int)amount)
			Hit_points -= amount;
		else
			Hit_points = 0;
	}
	else
		std::cout << "ClapTrap " << Name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Energy_points > 0 && Hit_points > 0)
	{	
		std::cout << "ClapTrap " << Name << " was healed, regains " << amount << " hit points"
			<< std::endl;
		Hit_points += amount;
		Energy_points--;
	}
	else
        std::cout << "ClapTrap " << Name << " can't repair because it has no energy points left!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment operator called!" << std::endl;
	if (this != &obj)
	{
		Name = obj.Name;
		Hit_points = obj.Hit_points;
		Energy_points = obj.Energy_points;
		Attack_damage = obj.Attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called!" << std::endl;
}
