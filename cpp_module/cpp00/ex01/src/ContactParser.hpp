#ifndef CONTACT_PARSER_HPP
# define CONTACT_PARSER_HPP
#include <iostream>
#include <cstdlib>
#include "CoutUtil.hpp"

class ContactParser {
	private:
	ContactParser();

	public:
	static const std::string valueCheck(std::string msg);
	static const std::string getline();
	static std::string resizeValue(std::string value);
};
#endif
