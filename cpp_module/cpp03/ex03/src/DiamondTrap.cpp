#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(){
	std::string msg = basicMsg();
	msg += "default constructor called";
	regularCout(msg);
	this->name = ClapTrap::name;
	ClapTrap::name = ClapTrap::name + "_clap_name";
	this->hit_points = 100;
	this->attack_damage = 50;
	this->energy_points = 30;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::string msg = basicMsg();
	msg += "constructor called";
	regularCout(msg);
	this->name = ClapTrap::name;
	ClapTrap::name = ClapTrap::name + "_clap_name";
	this->hit_points = 100;
	this->attack_damage = 50;
	this->energy_points = 30;
}

DiamondTrap::~DiamondTrap() {
	std::string msg = basicMsg();
	msg += "destructor called";
	regularCout(msg);
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamond_trap) {
	std::string msg = basicMsg();
	msg += "copy constructor called";
	regularCout(msg);

	*this = diamond_trap;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &diamond_trap) {
	std::string msg = basicMsg();
	msg += "copy assignment operator called";
	regularCout(msg);

	name = diamond_trap.name;
	ClapTrap::name = this->name + "_clap_name";
	hit_points = diamond_trap.hit_points;
	energy_points = diamond_trap.energy_points;
	attack_damage = diamond_trap.attack_damage;
	return *this;
}

std::string DiamondTrap::basicMsg() {
	return "DiamondTrap " + name + " ";
}

void DiamondTrap::info() {
	std::cout << std::endl;
	regularCout("[ Name ]: " + name );
	regularCout("[ HitPoints ]: " + std::to_string(hit_points));
	regularCout("[ EnergyPoints ]: " + std::to_string(energy_points));
	regularCout("[ AttackDamage ]: " + std::to_string(attack_damage));
	std::cout << std::endl;
}

void DiamondTrap::whoAmI() {
	regularCout("[Who Am I?");
	regularCout(this->name);
	regularCout(ClapTrap::name);
	regularCout("");
}
