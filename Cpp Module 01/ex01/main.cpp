#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie *Zombie = zombieHorde(N, "LMRAYTET");
	for(int i = 0; i < N; i++)
	{
		std::cout << i << " : ";
		Zombie->announce();
	}
	delete[] Zombie;
	return 0;
}