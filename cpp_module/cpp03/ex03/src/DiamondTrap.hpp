#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
	std::string name;

	protected:
	virtual std::string basicMsg();

	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	virtual ~DiamondTrap();
	DiamondTrap(DiamondTrap const &diamond_trap);
	DiamondTrap& operator=(DiamondTrap const &diamond_trap);
	void whoAmI();
	void info();
};
