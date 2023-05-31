#include "Saver.hpp"

Saver::Saver(Checker& checker)
	: checker(checker)
{}

Saver::~Saver(void) {}

void Saver::save(std::string filename, std::string str) {
	std::ofstream opf(filename + ".replace");

	this->checker.open_check(opf);
	opf << str;
	this->checker.failCheck(opf);
	opf.close();
}

