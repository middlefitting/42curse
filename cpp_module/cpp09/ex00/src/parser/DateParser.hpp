#pragma once

#include "../checker/DateChecker.hpp"
#include "../factory/DateFactory.hpp"
#include "IParser.hpp"

class DateParser : public IParser<t_date>
{
	private:
		ADateChecker *_checker;
		IFactory<t_date, std::string> *_date_factory;

	public:
		DateParser();
		~DateParser();
		DateParser(DateParser const &src);
		DateParser& operator=(DateParser const &src);
		t_date parse(const std::string &value) const;
};
