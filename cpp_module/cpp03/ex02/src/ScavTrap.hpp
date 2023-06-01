#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
	void guardGate();

	protected:
	std::string basicMsg();
	ScavTrap();

	public:
	ScavTrap(std::string name);
	virtual ~ScavTrap();
	ScavTrap(ScavTrap const &scav_trap);
	ScavTrap& operator=(ScavTrap const &scav_trap);

	void attack(const std::string& target);
};
