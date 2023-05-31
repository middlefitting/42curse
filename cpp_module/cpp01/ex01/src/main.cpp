#include "Zombie.hpp"

void leaks()
{
	system("leaks MoarBrainz");
}

int main(void) {
	Zombie* zombies = zombieHorde(10, "WorkingZombie");
	for (int i = 0; i < 10; i++) {
		zombies[i].announce();
	}
	delete [] zombies;
	system("leaks MoarBrainz");
	atexit(leaks);
	return 0;
}
