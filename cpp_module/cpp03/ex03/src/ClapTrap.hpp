#pragma once

#include <iostream>

class ClapTrap {
	protected:
	std::string name;
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;

	virtual std::string basicMsg();
	void regularCout(std::string msg);
	void warningCout(std::string msg);
	ClapTrap();

	public:
	ClapTrap(std::string name);
	virtual ~ClapTrap();
	ClapTrap(ClapTrap const &clap_trap);
	ClapTrap& operator=(ClapTrap const &clap_trap);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	virtual void info();
};
