#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav1;
	scav1.attack("LMCHELLEL");
	scav1.guardGate();

	ScavTrap scav2("L3ARBI");
	scav2.attack("LMTERBL");
	scav2.guardGate();

	ScavTrap scav3(scav2);
	scav3.attack("LMTERBAKH");

	scav1 = scav3;
	scav1.attack("LMBA3BEL");

	return 0;
}
