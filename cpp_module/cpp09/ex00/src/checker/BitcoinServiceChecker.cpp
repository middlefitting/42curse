#include "BitcoinServiceChecker.hpp"

BitcoinServiceChecker::BitcoinServiceChecker() {}

BitcoinServiceChecker::~BitcoinServiceChecker() {}

BitcoinServiceChecker::BitcoinServiceChecker(BitcoinServiceChecker const &src)
{
	(void) src;
}

BitcoinServiceChecker& BitcoinServiceChecker::operator=(BitcoinServiceChecker const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) BitcoinServiceChecker(src);
	return *this;
}

void BitcoinServiceChecker::fileHeadCheck(std::ifstream& file, std::string value) const
{
	std::string line;

	if (!std::getline(file, line))
		throw ExceptionThrower::InvalidFileException();

	fileFailCheck(file);

	if (line != value)
		throw ExceptionThrower::InvalidFileException();
}


void BitcoinServiceChecker::fileOpenCheck(std::ifstream& file) const
{
	if (!file.is_open())
		throw ExceptionThrower::FileOpenFailedException();
}

void BitcoinServiceChecker::fileFailCheck(std::ifstream& file) const
{
	if (file.fail())
		throw ExceptionThrower::FileFailedException();
}
