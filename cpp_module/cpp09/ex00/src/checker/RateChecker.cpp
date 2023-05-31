#include "RateChecker.hpp"

RateChecker::RateChecker() {}

RateChecker::~RateChecker() {}

RateChecker::RateChecker(RateChecker const &src)
{
	(void) src;
}

RateChecker& RateChecker::operator=(RateChecker const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) RateChecker(src);
	return *this;
}

void RateChecker::numberCheck(std::string value) const
{
	int idx = 0;

	signPasser(idx, value);
	digitChecker(idx, value);
	digitPasser(idx, value);
	dotPasser(idx, value);
	digitPasser(idx, value);
	nullChecker(idx, value);
}

void RateChecker::digitChecker(int &idx, const std::string value) const
{
	if (!std::isdigit(value[idx]))
		throw ExceptionThrower::BadInputException(value);
}

void RateChecker::nullChecker(int &idx, const std::string value) const
{
	if (value[idx] != '\0')
		throw ExceptionThrower::BadInputException(value);
}

void RateChecker::signPasser(int &idx, const std::string value) const
{
	if (value[idx] == '-' || value[idx] == '+')
		idx++;
}

void RateChecker::digitPasser(int &idx, const std::string value) const
{
	while (std::isdigit(value[idx]))
		idx++;
}

void RateChecker::dotPasser(int &idx, const std::string value) const
{
	if (value[idx] == '.')
	{
		idx++;
		digitChecker(idx, value);
	}
}
