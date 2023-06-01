#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::string msg = basicMsg();
	msg += "default constructor called";
	regularCout(msg);
	this->name = "";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::string msg = basicMsg();
	msg += "constructor called";
	regularCout(msg);
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::~ScavTrap() {
	std::string msg = basicMsg();
	msg += "destructor called";
	regularCout(msg);
}

ScavTrap::ScavTrap(ScavTrap const &scav_trap): ClapTrap(scav_trap) {
	std::string msg = basicMsg();
	msg += "copy constructor called";
	regularCout(msg);

	*this = scav_trap;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &scav_trap) {
	std::string msg = basicMsg();
	msg += "copy assignment operator called";
	regularCout(msg);

	name = scav_trap.name;
	hit_points = scav_trap.hit_points;
	energy_points = scav_trap.energy_points;
	attack_damage = scav_trap.attack_damage;
	return *this;
}

void ScavTrap::guardGate() {
	std::string msg = basicMsg();
	msg += "is now in Gate keeper mode...";
	regularCout(msg);
}

std::string ScavTrap::basicMsg() {
	return "ScavTrap " + name + " ";
}

void ScavTrap::attack(const std::string& target) {
	std::string msg = name;
	msg += (" attacks " + target);
	if (hit_points == 0) {
		msg += " impossible: I'm dead!";
		warningCout(msg);
	}
	else if (energy_points == 0) {
		msg += " impossible: Out of enrergy point!";
		warningCout(msg);
	}
	else {
		guardGate();
		msg += (", causing " + std::to_string(attack_damage) + " points of damage!");
		regularCout(msg);
		energy_points--;
	}
}
