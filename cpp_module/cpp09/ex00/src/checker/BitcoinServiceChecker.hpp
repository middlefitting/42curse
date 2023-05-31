#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ABitcoinServiceChecker.hpp"
#include "../exception/ExceptionThrower.hpp"



class BitcoinServiceChecker : public ABitcoinServiceChecker
{

	public:
		BitcoinServiceChecker();
		virtual ~BitcoinServiceChecker();
		BitcoinServiceChecker(BitcoinServiceChecker const &src);
		BitcoinServiceChecker& operator=(BitcoinServiceChecker const &src);

		virtual void	fileHeadCheck(std::ifstream& file, std::string value) const;
		virtual void	fileOpenCheck(std::ifstream& file) const;
		virtual void	fileFailCheck(std::ifstream& file) const;
};
