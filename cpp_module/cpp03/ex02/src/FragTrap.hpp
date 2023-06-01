#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	protected:
	std::string basicMsg();
	FragTrap();

	public:
	FragTrap(std::string name);
	virtual ~FragTrap();
	FragTrap(FragTrap const &frag_trap);
	FragTrap& operator=(FragTrap const &frag_trap);
	void highFivesGuys();
};
