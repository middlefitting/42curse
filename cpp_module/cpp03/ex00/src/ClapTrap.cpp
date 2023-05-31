#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	name(""), hit_points(10), energy_points(10), attack_damage(0)
{
	std::string msg = basicMsg();
	msg += "default constructor called";
	regularCout(msg);
}

ClapTrap::ClapTrap(std::string name):
	name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::string msg = basicMsg();
	msg += "one parameter constructor called";
	regularCout(msg);
}

ClapTrap::~ClapTrap() {
	std::string msg = basicMsg();
	msg += "destructor called";
	regularCout(msg);

}

ClapTrap::ClapTrap(ClapTrap const &clap_trap) {
	std::string msg = basicMsg();
	msg += "copy constructor called";
	regularCout(msg);

	*this = clap_trap;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &clap_trap) {
	std::string msg = basicMsg();
	msg += "copy assignment operator called";
	regularCout(msg);

	name = clap_trap.name;
	hit_points = clap_trap.hit_points;
	energy_points = clap_trap.energy_points;
	attack_damage = clap_trap.attack_damage;
	return *this;
}

std::string ClapTrap::basicMsg() {
	return "ClapTrap " + name + " ";
}

void ClapTrap::regularCout(std::string msg) {
	std::cout << msg << std::endl;
}

void ClapTrap::warningCout(std::string msg) {
	std::cout << "\033[33m" << msg <<"\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::string msg = basicMsg();
	msg += ("attacks " + target);
	if (hit_points == 0) {
		msg += " impossible: I'm dead!";
		warningCout(msg);
	}
	else if (energy_points == 0) {
		msg += " impossible: Out of enrergy point!";
		warningCout(msg);
	}
	else {
		msg += (", causing " + std::to_string(attack_damage) + " points of damage!");
		regularCout(msg);
		energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::string msg = basicMsg();
	msg += ("take damage " + std::to_string(amount));
	if (hit_points == 0)
	{
		msg += " but already dead";
		warningCout(msg);
	}
	else if (hit_points > amount)
	{
		regularCout(msg);
		hit_points -= amount;
	}
	else
	{
		msg += " and dead";
		regularCout(msg);
		hit_points = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::string msg = basicMsg();
	msg += ("repairs " + std::to_string(amount));
	if (hit_points == 0) {
		msg += " impossible: alreay dead!";
		warningCout(msg);
	}
	else if (energy_points == 0) {
		msg += " impossible: Out of enrergy point!";
		warningCout(msg);
	}
	else {
		if (amount > 4294967295 - hit_points)
			hit_points = 4294967295;
		else
			hit_points += amount;
		regularCout(msg);
		energy_points -= 1;
	}
}

void ClapTrap::info() {
	std::cout << std::endl;
	regularCout("[ Name ]: " + name );
	regularCout("[ HitPoints ]: " + std::to_string(hit_points));
	regularCout("[ EnergyPoints ]: " + std::to_string(energy_points));
	regularCout("[ AttackDamage ]: " + std::to_string(attack_damage));
	std::cout << std::endl;
}
