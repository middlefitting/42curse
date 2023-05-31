#pragma once

#include <iostream>
#include "CoutUtil.hpp"

class Brain {
	private:
	std::string ideas[100];

	public:
	Brain();
	Brain(std::string idea);
	virtual ~Brain();
	Brain(Brain const &Brain);
	Brain& operator=(Brain const &Brain);
	// std::string* getIdeas() const;
	void setIdeas(std::string idea);
	void braingStorming();
};
