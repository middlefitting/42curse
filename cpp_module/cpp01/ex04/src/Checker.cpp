#include "Checker.hpp"

Checker::Checker(void) {}

Checker::~Checker(void) {}

void	Checker::argc_check(int& argc) const{
	if (argc != 4) {
		std::cout << "Argument must be 3" << std::endl;
		std::exit(1);
	}
}

void	Checker::open_check(std::ifstream& file) const {
	if (!file.is_open()) {
		std::cout << "Input file open failed!" << std::endl;
		std::exit(1);
	}
}

void	Checker::open_check(std::ofstream& file) const {
	if (!file.is_open()) {
		std::cout << "Output file open failed!" << std::endl;
		std::exit(1);
	}
}

void	Checker::failCheck(std::ifstream& file) const {
	if (file.fail()) {
		std::cout << "Input file Error occured!" << std::endl;
		std::exit(1);
	}
}

void	Checker::failCheck(std::ofstream& file) const {
	if (file.fail()) {
		std::cout << "output file get Error occured!" << std::endl;
		std::exit(1);
	}
}
