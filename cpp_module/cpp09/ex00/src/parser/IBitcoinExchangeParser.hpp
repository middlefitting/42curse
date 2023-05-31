#pragma once

#include <string>
#include "../exception/ExceptionThrower.hpp"

template<typename T>
class IBitcoinExchangeParser
: public IParser<T>
{
	public:
		virtual ~IBitcoinExchangeParser() {}
		virtual	T parseBillData(std::string const &data) const = 0;
};
