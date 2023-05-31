#ifndef BitcoinService_HPP
# define BitcoinService_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include "../checker/BitcoinServiceChecker.hpp"
#include "../repository/BitcoinExchange.hpp"
#include "IBitcoinService.hpp"

class BitcoinService : public IBitcoinService
{
	private:
		ABitcoinServiceChecker *_checker;
		IBitcoinExchange *_bitcoin_repository;

	public:
		BitcoinService();
		virtual ~BitcoinService();
		BitcoinService(BitcoinService const &src);
		BitcoinService& operator=(BitcoinService const &src);
		virtual void initDb() const;
		virtual void calc(std::string filename) const;
};

#endif
