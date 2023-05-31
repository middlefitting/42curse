#include "DateFactory.hpp"

DateFactory::DateFactory()
{
	_checker = new DateChecker();
}

DateFactory::~DateFactory()
{
	delete _checker;
}

DateFactory::DateFactory(DateFactory const &src)
{
	(void) src;
	_checker = new DateChecker();
}

DateFactory& DateFactory::operator=(DateFactory const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) DateFactory(src);
	return *this;
}

/*가변인자 처리, c++ 98에서는 템플릿 가변인자도 못쓰고 va_list는 기깔난 예외처리가 불가능하다는게 개탄스럽다*/
t_date DateFactory::getProduct(std::string value, ...) const
{
	t_date date;

	_checker->dateFormCheck(value);
	initDate(date, value);
	_checker->dateValidateChecker(date, value);

	return date;
}

void DateFactory::initDate(t_date &date, std::string value) const
{

	std::string year = value.substr(0, 4);
	std::string month = value.substr(5, 2);
	std::string day = value.substr(8, 2);

	_checker->numberChecker(year);
	_checker->numberChecker(month);
	_checker->numberChecker(day);

	date.year = std::atoi(year.c_str());
	date.month = std::atoi(month.c_str());
	date.day = std::atoi(day.c_str());
}
