#include "main.hpp"

int main() {
	Phonebook phonebook;

	CoutUtil::infoCout("Weclome Phonebook!");
	CoutUtil::infoCout("[ADD, SEARCH, EXIT] command to start!");
	while (true)
	{
		CoutUtil::infoCoutNoEndl("INPUT COMMAND: ");
		std::string cmd = ContactParser::getline();
		if (cmd == "ADD")
			phonebook.append();
		else if (cmd == "SEARCH")
		{
			phonebook.info();
			CoutUtil::infoCoutNoEndl("INPUT INDEX: ");
			phonebook.contactInfo(atoi(ContactParser::getline().c_str()));
		}
		else if (cmd == "EXIT")
			break ;
		else
			CoutUtil::warningCout("COMMAND NOT FOUND: [ADD, SEARCH, EXIT]");
	}
	return 0;
}
