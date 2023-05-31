#include "DateChecker.hpp"

DateChecker::DateChecker()
{
	_days_of_month.insert(std::make_pair(1, 31));
	_days_of_month.insert(std::make_pair(2, 28));
	_days_of_month.insert(std::make_pair(3, 31));
	_days_of_month.insert(std::make_pair(4, 30));
	_days_of_month.insert(std::make_pair(5, 31));
	_days_of_month.insert(std::make_pair(6, 30));
	_days_of_month.insert(std::make_pair(7, 31));
	_days_of_month.insert(std::make_pair(8, 31));
	_days_of_month.insert(std::make_pair(9, 30));
	_days_of_month.insert(std::make_pair(10, 31));
	_days_of_month.insert(std::make_pair(11, 30));
	_days_of_month.insert(std::make_pair(12, 31));
}

DateChecker::~DateChecker() {}

DateChecker::DateChecker(DateChecker const &src)
{
	(void) src;
}

DateChecker& DateChecker::operator=(DateChecker const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) DateChecker(src);
	return *this;
}

void DateChecker::dateFormCheck(std::string value) const
{
	lengthChecker(value);
	hyphenChecker(value);
}

void DateChecker::lengthChecker(std::string value) const
{
	if (value.length() != 10)
		throw ExceptionThrower::BadInputException(value);
}

void DateChecker::hyphenChecker(std::string value) const
{
	if (value[4] != '-' || value[7] != '-')
		throw ExceptionThrower::BadInputException(value);
}

void DateChecker::numberChecker(std::string value) const
{
	for (int i = 0; i < static_cast<int>(value.length()); i++)
	{
		if (!isdigit(value[i]))
			throw ExceptionThrower::BadInputException(value);
	}
}

void DateChecker::dateValidateChecker(t_date &date, std::string value) const
{
	if (date.month == 0	|| date.month > 12)
		throw ExceptionThrower::BadInputException(value);

	int leap_year_flag = 0;
	if (date.month == 2)
	{
		if (date.year % 4 == 0)
			leap_year_flag = 1;
		if (date.year % 100 == 0)
			leap_year_flag = 0;
		if (date.year % 400 == 0)
			leap_year_flag = 1;
	}

	int month_day = _days_of_month.find(date.month)->second + leap_year_flag;

	if (date.day == 0 || date.day > month_day)
		throw ExceptionThrower::BadInputException(value);
}
