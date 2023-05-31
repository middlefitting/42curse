#include "Zombie.hpp"

void leaks()
{
	system("leaks BraiiiiiiinnnzzzZ");
}

int	main(void) {
	Zombie working_zombie = Zombie("WorkingZombie");
	working_zombie.announce();

	Zombie *hello_zombie = newZombie("HelloZombie");
	delete hello_zombie;

	randomChump("WorldZombie");
	system("leaks BraiiiiiiinnnzzzZ");
	atexit(leaks);
	return 0;
}
