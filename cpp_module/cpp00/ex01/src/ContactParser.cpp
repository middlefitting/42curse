#include "ContactParser.hpp"

ContactParser::ContactParser() {};

const std::string ContactParser::valueCheck(std::string msg) {
	std::string result;

	while (true)
	{
		CoutUtil::infoCoutNoEndl(msg);
		result = getline();
		if (result.length() != 0)
			break;
		CoutUtil::warningCout("INVALID VALUE: EMPTY!");
	}
	return result;
}

std::string ContactParser::resizeValue(std::string value) {
	if (value.length() >= 10) {
		value.resize(9);
		value.resize(10, '.');
	}
	return value;
}

const std::string ContactParser::getline() {
	std::string result;
	std::getline(std::cin, result);
	if (std::cin.eof())
		std::exit(0);
	return result;
}
