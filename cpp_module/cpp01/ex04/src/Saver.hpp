#ifndef SAVER_HPP
# define SAVER_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Checker.hpp"

class Saver {
	private:
	Checker& checker;

	public:
	Saver(Checker& checker);
	~Saver(void);
	void save(std::string filename, std::string str);
};

#endif
