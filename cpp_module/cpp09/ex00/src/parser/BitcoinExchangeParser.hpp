#pragma once

#include "../checker/Checker.hpp"
#include "IParser.hpp"
#include "IBitcoinExchangeParser.hpp"
#include "ExchangRateParser.hpp"
#include "DateParser.hpp"

typedef struct s_BitcoinExchangeDts
{
	int date;
	float exchange_rate;
} t_BitcoinExchangeDts;

class BitcoinExchangeParser : public IBitcoinExchangeParser<t_BitcoinExchangeDts>
{
	private:
		IChecker *_checker;
		IParser<float> *_exchangeRateParser;
		IParser<t_date> *_dateParser;
		t_BitcoinExchangeDts parseLogic(const std::string &value) const;

	public:
		BitcoinExchangeParser();
		virtual ~BitcoinExchangeParser();
		BitcoinExchangeParser(BitcoinExchangeParser const &src);
		BitcoinExchangeParser& operator=(BitcoinExchangeParser const &src);
		virtual t_BitcoinExchangeDts parse(const std::string &value) const;
		virtual	t_BitcoinExchangeDts parseBillData(std::string const &data) const;
};
