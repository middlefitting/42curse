#include "CoutUtil.hpp"

/*Default*/
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

CoutUtil &CoutUtil::operator=(CoutUtil const &cout_util) {
  std::string msg = "CoutUtil copy assignment operator called";
  regularCout(msg);
  (void)cout_util;
  return *this;
}

/*Regular*/
void CoutUtil::regularCout(std::string msg) { std::cout << msg << std::endl; }

void CoutUtil::regularCoutNoEndl(std::string msg) { std::cout << msg; }

/*Warning*/
void CoutUtil::warningCout(std::string msg) {
  std::cout << "\033[33m" << msg << "\033[0m" << std::endl;
}

void CoutUtil::warningCoutNoEndl(std::string msg) {
  std::cout << "\033[33m" << msg << "\033[0m";
}

/*Info*/
void CoutUtil::infoCout(std::string msg) {
  std::cout << "\033[36m" << msg << "\033[0m" << std::endl;
}

void CoutUtil::infoCoutNoEndl(std::string msg) {
  std::cout << "\033[36m" << msg << "\033[0m";
}

/*Error*/
void CoutUtil::errorCout(std::string msg) {
  std::cerr << "\033[31m" << msg << "\033[0m" << std::endl;
}

void CoutUtil::errorCoutNoEndl(std::string msg) {
  std::cerr << "\033[31m" << msg << "\033[0m";
}
