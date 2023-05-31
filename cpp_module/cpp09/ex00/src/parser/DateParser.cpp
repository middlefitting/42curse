#include "DateParser.hpp"

DateParser::DateParser()
{
	_checker = new DateChecker();
	_date_factory = new DateFactory();
}

DateParser::~DateParser()
{
	delete _checker;
	delete _date_factory;
}

DateParser::DateParser(DateParser const &src)
{
	(void) src;
	_checker = new DateChecker();
	_date_factory = new DateFactory();
}

DateParser& DateParser::operator=(DateParser const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) DateParser(src);
	return *this;
}

t_date DateParser::parse(const std::string &value) const
{
	_checker->emptyCheck(value);
	t_date date = _date_factory->getProduct(value);
	return date;
}
