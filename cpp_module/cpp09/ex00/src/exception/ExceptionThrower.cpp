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
ExceptionThrower::BadInputException::BadInputException(std::string message)
: std::invalid_argument("Error: bad input => " + message)
{}

const char* ExceptionThrower::BadInputException::what() const throw()
{
	return std::invalid_argument::what();
}


ExceptionThrower::NotPositiveNumberException::NotPositiveNumberException()
: std::invalid_argument("Error: not a positive number.")
{}

const char* ExceptionThrower::NotPositiveNumberException::what() const throw()
{
	return std::invalid_argument::what();
}


ExceptionThrower::TooLargeNumberException::TooLargeNumberException()
: std::invalid_argument("Error: too large a number.")
{}

const char* ExceptionThrower::TooLargeNumberException::what() const throw()
{
	return std::invalid_argument::what();
}


ExceptionThrower::DataNotExistException::DataNotExistException()
: std::invalid_argument("Error: data not exist in db.")
{}

const char* ExceptionThrower::DataNotExistException::what() const throw()
{
	return std::invalid_argument::what();
}


/*Runtime Exceptions*/
ExceptionThrower::FileOpenFailedException::FileOpenFailedException()
: std::runtime_error("Error: could not open file.")
{}

const char* ExceptionThrower::FileOpenFailedException::what() const throw()
{
	return std::runtime_error::what();
}


ExceptionThrower::FileFailedException::FileFailedException()
: std::runtime_error("Error: file failed by unknown reason.")
{}

const char* ExceptionThrower::FileFailedException::what() const throw()
{
	return std::runtime_error::what();
}


ExceptionThrower::InvalidFileException::InvalidFileException()
: std::runtime_error("Error: invalid file.")
{}

const char* ExceptionThrower::InvalidFileException::what() const throw()
{
	return std::runtime_error::what();
}


ExceptionThrower::ArgCheckFailedException::ArgCheckFailedException()
: std::runtime_error("Error: program need 1 argument.")
{}

const char* ExceptionThrower::ArgCheckFailedException::what() const throw()
{
	return std::runtime_error::what();
}



