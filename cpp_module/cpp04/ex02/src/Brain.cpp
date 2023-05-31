#include "Brain.hpp"

Brain::Brain() {
	std::string msg = + "Brain default constructor called";
	CoutUtil::regularCout(msg);
	for (int i = 0; i < 100; i ++)
		ideas[i] = "Default Idea: " + std::to_string(i);
}

Brain::Brain(std::string idea) {
	std::string msg = + "Brain constructor called";
	CoutUtil::regularCout(msg);
	for (int i = 0; i < 100; i ++)
		ideas[i] = idea + ": " + std::to_string(i);
}

Brain::~Brain() {
	std::string msg = + "Brain destructor called";
	CoutUtil::regularCout(msg);
}

Brain::Brain(Brain const &brain) {
	std::string msg = + "Brain copy constructor called";
	CoutUtil::regularCout(msg);
	*this = brain;
}

Brain& Brain::operator=(Brain const &brain) {
	std::string msg = + "Brain copy assignment operator called";
	CoutUtil::regularCout(msg);
	for (int i = 0; i < 100; i ++)
		ideas[i] = brain.ideas[i];
	return *this;
}

void Brain::setIdeas(std::string idea) {
	for (int i = 0; i < 100; i ++)
		ideas[i] = idea + ": " + std::to_string(i);
}

void Brain::braingStorming() {
	CoutUtil::regularCout("braingStorming...");
	for (int i = 0; i < 100; i ++)
		CoutUtil::regularCout(ideas[i]);
}
