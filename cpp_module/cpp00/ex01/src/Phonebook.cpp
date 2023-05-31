#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->ind = 0;
}

void Phonebook::append()
{
	if (this->ind < 8)
	{
		this->contacts[this->ind].setting();
		this->ind += 1;
	}
	else
	{
		Contact temp = contacts[0];
		for (int i = 0; i < 7; i++)
			this->contacts[i] = this->contacts[i + 1];
		this->contacts[7] = temp;
		contacts[7].setting();
	}
}

void Phonebook::contactInfo(int index) {
	index--;
	if (index >= this->ind || index < 0)
		CoutUtil::warningCout("INVALID VALUE: OUT OF INDEX!");
	else
		this->contacts[index].info();
}

void Phonebook::info()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	for (int i = 0; i < this->ind; i++)
	{
		Contact contact = this->contacts[i];
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << contact.getFirstName() << "|";
		std::cout << std::setw(10) << contact.getLastName() << "|";
		std::cout << std::setw(10) << contact.getNickname() << "|" << std::endl;
	}
}


