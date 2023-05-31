#include "BitcoinExchange.hpp"

/**비트 코인 데이터를 저장한다*/
BitcoinExchange::BitcoinExchange()
{
	_parser = new BitcoinExchangeParser();
}


BitcoinExchange::~BitcoinExchange()
{
	delete _parser;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
: _parser(src._parser)
{
	this->_db = std::map<int, float>(src._db);
	_parser = new BitcoinExchangeParser();
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &src) {
	if (this != &src)
		return *this;
	delete this;
	new (this) BitcoinExchange(src);
	return *this;
}

void BitcoinExchange::insert(const std::string &data)
{
	try
	{
		s_BitcoinExchangeDts dts = _parser->parse(data);
		_db.insert(std::pair<int, float>(dts.date, dts.exchange_rate));
	}
	catch(const std::invalid_argument& e)
	{
		CoutUtil::warningCout(e.what());

	}
}

void BitcoinExchange::calc(const std::string &data)
{
	try
	{
		s_BitcoinExchangeDts dts = _parser->parseBillData(data);

		while (dts.date > 0 && _db.find(dts.date) == _db.end())
			dts.date--;
		if (dts.date > 0)
			calcMsg(data, dts);
		else
			throw ExceptionThrower::DataNotExistException();
	}
	catch(const std::invalid_argument& e)
	{
		CoutUtil::warningCout(e.what());
	}
}

void BitcoinExchange::calcMsg(std::string const &data, t_BitcoinExchangeDts const &dts)
{
	CoutUtil::regularCoutNoEndl(data.substr(0, data.find('|') - 1));
	CoutUtil::regularCoutNoEndl(" => ");
	CoutUtil::regularCoutNoEndl(data.substr(data.find('|') + 2));
	CoutUtil::regularCoutNoEndl(" = ");
	CoutUtil::regularCout(_db.find(dts.date)->second * dts.exchange_rate);
}
