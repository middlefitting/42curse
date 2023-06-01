#pragma once

#include <iostream>

class ClapTrap {
	private:
	std::string name;
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;

	std::string basicMsg();
	void regularCout(std::string msg);
	void warningCout(std::string msg);
	ClapTrap();

	public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(ClapTrap const &clap_trap);
	ClapTrap& operator=(ClapTrap const &clap_trap);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void info();


	// std::string getName();
	// int getHitPoints();
	// int getEnergyPoints();
	// int getAttackDamage();
	// void setName();
	// void setEnergyPoints();
	// void setEnergyPoints();
	// void setEnergyPoints();
};
