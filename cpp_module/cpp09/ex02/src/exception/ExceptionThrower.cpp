#include "ExceptionThrower.hpp"

/*Default*/
ExceptionThrower::ExceptionThrower() {}

ExceptionThrower::~ExceptionThrower() {}

ExceptionThrower::ExceptionThrower(ExceptionThrower const &src) { (void) src; }

ExceptionThrower& ExceptionThrower::operator=(ExceptionThrower const &src) {
	if (this == &src)
		return *this;
	delete this;
	new (this) ExceptionThrower(src);
	return *this;
}


/*Invalid Argument Exceptions*/
ExceptionThrower::DefaultException::DefaultException()
: std::invalid_argument("Error")
{}

const char* ExceptionThrower::DefaultException::what() const throw()
{
	return std::invalid_argument::what();
}
