#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombieHord = new Zombie[N];
	for(int i = 0; i < N; i++)
		zombieHord[i].setName(name);
	return zombieHord;
}