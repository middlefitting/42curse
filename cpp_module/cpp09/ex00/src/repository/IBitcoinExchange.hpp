#pragma once

#include <string>

class IBitcoinExchange
{
	public:
		virtual ~IBitcoinExchange() {};
		virtual void insert(std::string const &data) = 0;
		virtual	void calc(std::string const &data) = 0;
};
