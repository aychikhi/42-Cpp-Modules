#include "Zombie.hpp"

int main()
{
	Zombie *Zombie;
	randomChump("LMRAYTET");
	Zombie = newZombie("LMHAYTEK");
	Zombie->announce();
	delete Zombie;
}