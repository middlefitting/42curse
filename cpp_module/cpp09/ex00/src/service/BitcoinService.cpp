#include "BitcoinService.hpp"


BitcoinService::BitcoinService()
{
	_checker = new BitcoinServiceChecker();
	_bitcoin_repository = new BitcoinExchange();
}

BitcoinService::~BitcoinService(void)
{
	delete _checker;
	delete _bitcoin_repository;
}

BitcoinService::BitcoinService(BitcoinService const &src)
{
	(void) src;
	_checker = new BitcoinServiceChecker();
	_bitcoin_repository = new BitcoinExchange();
}

BitcoinService& BitcoinService::operator=(BitcoinService const &src) {
	if (this == &src)
		return *this;
	delete this;
	new (this) BitcoinService(src);
	return *this;
}

void BitcoinService::initDb() const {
	std::string line;
	std::ifstream ipf("data.csv");

	_checker->fileOpenCheck(ipf);
	_checker->fileHeadCheck(ipf, "date,exchange_rate");

	while (std::getline(ipf, line)) {
		_checker->fileFailCheck(ipf);
		_bitcoin_repository->insert(line);
	}

	ipf.close();
}

void BitcoinService::calc(std::string filename) const
{
	std::string line;
	std::ifstream ipf(filename);

	_checker->fileOpenCheck(ipf);
	_checker->fileHeadCheck(ipf, "date | value");

	while (std::getline(ipf, line)) {
		_checker->fileFailCheck(ipf);
		_bitcoin_repository->calc(line);
	}

	ipf.close();
}
