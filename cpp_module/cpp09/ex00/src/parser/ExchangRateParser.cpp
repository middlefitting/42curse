#include "ExchangRateParser.hpp"

ExchangRateParser::ExchangRateParser()
{
	_checker = new RateChecker();
}

ExchangRateParser::~ExchangRateParser()
{
	delete _checker;
}

ExchangRateParser::ExchangRateParser(ExchangRateParser const &src)
{
	(void) src;
	_checker = new RateChecker();
}

ExchangRateParser& ExchangRateParser::operator=(ExchangRateParser const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) ExchangRateParser(src);
	return *this;
}

float ExchangRateParser::parse(const std::string &value) const
{
	float result;
	_checker->emptyCheck(value);
	_checker->numberCheck(value);
	result = static_cast<float>(std::atof(value.c_str()));
	return result;
}
