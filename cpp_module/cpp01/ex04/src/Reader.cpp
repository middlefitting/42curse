#include "Reader.hpp"

Reader::Reader(Checker& checker)
	: checker(checker)
{}

Reader::~Reader(void) {}

std::string Reader::read(std::string filename) {
	std::string result = "";
	std::string line;

	std::ifstream ipf(filename);
	checker.open_check(ipf);
	while (std::getline(ipf, line)) {
		checker.failCheck(ipf);
		result += line;
		if (!ipf.eof())
			result += "\n";
	}
	ipf.close();
	return result;
}

