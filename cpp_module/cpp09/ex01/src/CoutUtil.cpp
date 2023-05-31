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
