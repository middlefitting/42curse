
#pragma once

#include "../checker/RateChecker.hpp"
#include "IParser.hpp"
#include "vector"
#include <string>
#include <iostream>
#include <sstream>


class VectorParser : public IParser<std::vector<int> >
{
	private:
		ARateChecker *_checker;
		std::vector<std::string> split(const char *str, char delimiter) const;

	public:
		VectorParser();
		~VectorParser();
		VectorParser(VectorParser const &src);
		VectorParser& operator=(VectorParser const &src);
		virtual std::vector<int> parse(int argc, char **argv) const;
};
