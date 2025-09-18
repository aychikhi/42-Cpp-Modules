#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diam("LMFERBL");
	diam.attack("LMCHELLEL");
	diam.takeDamage(10);
	diam.beRepaired(10);
	diam.guardGate();
	diam.highFivesGuys();
	diam.whoAmI();
	return 0;
}
