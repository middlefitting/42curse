#include "CoutUtil.hpp"

CoutUtil::CoutUtil() {
	std::string msg = "CoutUtil default constructor called";
	regularCout(msg);
}

CoutUtil::~CoutUtil() {
	std::string msg = "CoutUtil destructor called";
	regularCout(msg);
}

CoutUtil::CoutUtil(CoutUtil const &cout_util) {
	std::string msg = "CoutUtil copy constructor called";
	regularCout(msg);
	*this = cout_util;
}

CoutUtil& CoutUtil::operator=(CoutUtil const &cout_util) {
	std::string msg = "CoutUtil copy assignment operator called";
	regularCout(msg);
	(void) cout_util;
	return *this;
}

void CoutUtil::regularCout(std::string msg) {
	std::cout << msg << std::endl;
}

void CoutUtil::warningCout(std::string msg) {
	std::cout << "\033[33m" << msg <<"\033[0m" << std::endl;
}

void CoutUtil::infoCout(std::string msg) {
	std::cout << "\033[36m" << msg <<"\033[0m" << std::endl;
}
