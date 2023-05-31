#include "Checker.hpp"

Checker::Checker() {}

Checker::~Checker() {}

Checker::Checker(Checker const &src)
{
	(void) src;
}

Checker& Checker::operator=(Checker const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) Checker(src);
	return *this;
}

void Checker::emptyCheck(std::string value) const {
	if (value.empty())
		throw ExceptionThrower::DefaultException();
}

void Checker::existCheck(std::string value, char c) const {
	if (value.find(c) == std::string::npos)
		throw ExceptionThrower::DefaultException();
}

void Checker::sizeCheck(std::string value, char c) const {
	existCheck(value, c);
	if (value.find(c) == 0)
		throw ExceptionThrower::DefaultException();
	if (value.find(c) == value.size() - 1)
		throw ExceptionThrower::DefaultException();
}

void Checker::positiveNumberCheck(int value) const
{
	if (value < 0)
		throw ExceptionThrower::DefaultException();
}

void Checker::largeNumberCheck(float value) const
{
	if (value > 1000.0f)
		throw ExceptionThrower::DefaultException();
}

