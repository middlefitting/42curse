#pragma once

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	private:
	void guardGate();

	protected:
	virtual std::string basicMsg();

	public:
	ScavTrap();
	ScavTrap(std::string name);
	virtual ~ScavTrap();
	ScavTrap(ScavTrap const &scav_trap);
	ScavTrap& operator=(ScavTrap const &scav_trap);

	virtual void attack(const std::string& target);
};
