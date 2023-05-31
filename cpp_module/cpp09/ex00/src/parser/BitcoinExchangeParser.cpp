#include "BitcoinExchangeParser.hpp"

BitcoinExchangeParser::BitcoinExchangeParser()
{
	_checker = new Checker();
	_exchangeRateParser = new ExchangRateParser();
	_dateParser = new DateParser();
}

BitcoinExchangeParser::~BitcoinExchangeParser()
{
	delete _checker;
	delete _exchangeRateParser;
	delete _dateParser;
}

BitcoinExchangeParser::BitcoinExchangeParser(BitcoinExchangeParser const &src)
{
	(void) src;
	_checker = new Checker();
	_exchangeRateParser = new ExchangRateParser();
	_dateParser = new DateParser();
}

BitcoinExchangeParser& BitcoinExchangeParser::operator=(BitcoinExchangeParser const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) BitcoinExchangeParser(src);
	return *this;
}

t_BitcoinExchangeDts BitcoinExchangeParser::parse(const std::string &value) const
{
	try
	{
		return parseLogic(value);
	}
	catch(ExceptionThrower::BadInputException &e)
	{
		throw ExceptionThrower::BadInputException(value);
	}
}

t_BitcoinExchangeDts BitcoinExchangeParser::parseLogic(const std::string &value) const
{
	t_BitcoinExchangeDts dts;

	_checker->emptyCheck(value);
	_checker->existCheck(value, ',');
	_checker->sizeCheck(value, ',');

	std::string exchange_rate = value.substr(value.find(',') + 1);
	dts.exchange_rate = _exchangeRateParser->parse(exchange_rate);
	_checker->positiveNumberCheck(dts.exchange_rate);

	std::string raw_date = value.substr(0, value.find(','));
	t_date date = _dateParser->parse(raw_date);
	dts.date = date.year * 400 + date.month * 32 + date.day;
	return dts;
}
t_BitcoinExchangeDts BitcoinExchangeParser::parseBillData(const std::string &value) const
{
	t_BitcoinExchangeDts dts;

	_checker->emptyCheck(value);
	_checker->existCheck(value, '|');
	_checker->sizeCheck(value, '|');

	std::string exchange_rate = value.substr(value.find('|') + 2);

	dts.exchange_rate = _exchangeRateParser->parse(exchange_rate);
	_checker->positiveNumberCheck(dts.exchange_rate);
	_checker->largeNumberCheck(dts.exchange_rate);

	std::string raw_date = value.substr(0, value.find('|') - 1);
	t_date date = _dateParser->parse(raw_date);
	dts.date = date.year * 400 + date.month * 32 + date.day;
	return dts;
}
