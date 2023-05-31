#pragma once

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	protected:
	virtual std::string basicMsg();

	public:
	FragTrap();
	FragTrap(std::string name);
	virtual ~FragTrap();
	FragTrap(FragTrap const &frag_trap);
	FragTrap& operator=(FragTrap const &frag_trap);
	void highFivesGuys();
};
