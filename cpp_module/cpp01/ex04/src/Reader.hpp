#ifndef READER_HPP
# define READER_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Checker.hpp"

class Reader {
	private:
		Checker& checker;

	public:
		Reader(Checker& checker);
		~Reader(void);
		std::string read(std::string filename);
};

#endif
