#include "CoutUtil.hpp"
#include "repository/BitcoinExchange.hpp"
#include "service/BitcoinService.hpp"
#include "exception/ExceptionThrower.hpp"


void leaks()
{
	system("leaks btc");
}

void argcCheck(int argc)
{
	if (argc != 2)
		throw ExceptionThrower::ArgCheckFailedException();
}

int main(int argc, char **argv)
{
	CoutUtil::infoCout("/********** BITCOIN TEST **********/");

	try
	{
		CoutUtil::infoCout("/*ARGUMENT CHECK*/");
		argcCheck(argc);

		const IBitcoinService &bitcoin_service = BitcoinService();

		CoutUtil::infoCout("/*READ DB FILE*/");
		bitcoin_service.initDb();

		CoutUtil::infoCout("/*CALC*/");
		bitcoin_service.calc(argv[1]);
	}
	catch(const std::exception& e)
	{
		CoutUtil::errorCout(e.what());
		// system("leaks btc");
		// atexit(leaks);
		return 0;
	}

	// system("leaks btc");
	// atexit(leaks);
	return 0;
}
