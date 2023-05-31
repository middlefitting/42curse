#pragma once

#include <map>
#include <fstream>
#include "../CoutUtil.hpp"
#include "../parser/BitcoinExchangeParser.hpp"
#include "../exception/ExceptionThrower.hpp"
#include "IBitcoinExchange.hpp"

class BitcoinExchange: public IBitcoinExchange
{
	private:
		std::map<int, float> _db;
		IBitcoinExchangeParser<t_BitcoinExchangeDts> *_parser;
		void calcMsg(std::string const &data, t_BitcoinExchangeDts const &dts);

	public:
		BitcoinExchange();
		virtual ~BitcoinExchange();
		BitcoinExchange& operator=(BitcoinExchange const &src);
		BitcoinExchange(BitcoinExchange const &src);
		virtual void insert(std::string const &data);
		virtual	void calc(std::string const &data);
};
