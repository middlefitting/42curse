#include "Contact.hpp"

Contact::Contact() {};

void Contact::setting() {
	this->first_name = ContactParser::valueCheck("First name: ");
	this->last_name = ContactParser::valueCheck("Last name: ");
	this->nickname = ContactParser::valueCheck("Nickname: ");
	this->phone_number = ContactParser::valueCheck("Phone number: ");
	this->darkest_secret = ContactParser::valueCheck("Darkest secret: ");
}


std::string Contact::getFirstName() {
	return ContactParser::resizeValue(this->first_name);
}

std::string Contact::getLastName() {
	return ContactParser::resizeValue(this->last_name);
}

std::string Contact::getNickname() {
	return ContactParser::resizeValue(this->nickname);
}

void Contact::info() {
	CoutUtil::regularCout("- First name: " + this->first_name);
	CoutUtil::regularCout("- Last name: " + this->last_name);
	CoutUtil::regularCout("- Nickname: " + this->nickname);
	CoutUtil::regularCout("- Phone number: " + this->phone_number);
	CoutUtil::regularCout("- Darkest secret: " + this->darkest_secret);

	// std::cout << "- First name: " <<  this->first_name << std::endl;
	// std::cout << "- Last name: " <<  this->last_name << std::endl;
	// std::cout << "- Nickname: " <<  this->nickname << std::endl;
	// std::cout << "- Phone number: " <<  this->phone_number << std::endl;
	// std::cout << "- Darkest secret: " <<  this->darkest_secret << std::endl;
}


