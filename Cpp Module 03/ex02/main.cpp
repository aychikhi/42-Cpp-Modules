#include "FragTrap.hpp"

int main()
{
	FragTrap frag1;
	frag1.attack("LMCHELLEL");
	frag1.highFivesGuys();

	FragTrap frag2("L3ARBI");
	frag2.attack("LMTERBL");
	frag2.highFivesGuys();

	FragTrap frag3(frag2);
	frag3.attack("LMTERBAKH");

	frag1 = frag3;
	frag1.attack("LMBA3BEL");

	return 0;
}
