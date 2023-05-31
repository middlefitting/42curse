#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	std::string msg = basicMsg();
	msg += "default constructor called";
	regularCout(msg);
	this->name = "";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::string msg = basicMsg();
	msg += "constructor called";
	regularCout(msg);
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::~FragTrap() {
	std::string msg = basicMsg();
	msg += "destructor called";
	regularCout(msg);
}

FragTrap::FragTrap(FragTrap const &frag_trap): ClapTrap(frag_trap) {
	std::string msg = basicMsg();
	msg += "copy constructor called";
	regularCout(msg);

	*this = frag_trap;
}

FragTrap& FragTrap::operator=(FragTrap const &frag_trap) {
	std::string msg = basicMsg();
	msg += "copy assignment operator called";
	regularCout(msg);

	name = frag_trap.name;
	hit_points = frag_trap.hit_points;
	energy_points = frag_trap.energy_points;
	attack_damage = frag_trap.attack_damage;
	return *this;
}

std::string FragTrap::basicMsg() {
	return "FragTrap " + name + " ";
}

void FragTrap::highFivesGuys() {
	std::string msg = basicMsg();
	if (hit_points) {
		msg += "high fives guys!";
		regularCout(msg);
	}
	else {
		msg += "impossible. already dead!";
		warningCout(msg);
	}
}
