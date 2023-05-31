
#pragma once

#include "../checker/RateChecker.hpp"
#include "IParser.hpp"

class ExchangRateParser : public IParser<float>
{
	private:
		ARateChecker *_checker;

	public:
		ExchangRateParser();
		~ExchangRateParser();
		ExchangRateParser(ExchangRateParser const &src);
		ExchangRateParser& operator=(ExchangRateParser const &src);
		float parse(const std::string &value) const;
};
