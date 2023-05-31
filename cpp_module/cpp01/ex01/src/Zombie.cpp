#include "Zombie.hpp"

Zombie::Zombie(void) {};

Zombie::Zombie(std::string name) {
	this->name = name;
}

void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << this->name << ": Goodbye" << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}
