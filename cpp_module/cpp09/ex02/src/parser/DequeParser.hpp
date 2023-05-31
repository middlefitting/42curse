
#pragma once

#include "../checker/RateChecker.hpp"
#include "IParser.hpp"
#include "deque"
#include <string>
#include <iostream>
#include <sstream>


class DequeParser : public IParser<std::deque<int> >
{
	private:
		ARateChecker *_checker;
		std::deque<std::string> split(const char *str, char delimiter) const;

	public:
		DequeParser();
		~DequeParser();
		DequeParser(DequeParser const &src);
		DequeParser& operator=(DequeParser const &src);
		virtual std::deque<int> parse(int argc, char **argv) const;
};
