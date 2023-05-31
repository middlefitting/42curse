#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
# include <iomanip>
#include "Contact.hpp"

class Phonebook {
	private:
	Contact	contacts[8];
	int			ind;

	public:
	Phonebook();
	void append();
	void contactInfo(int index);
	void info();
};
#endif
