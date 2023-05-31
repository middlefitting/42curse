#pragma once

#include <cstdarg>
#include "IFactory.hpp"
#include "../checker/DateChecker.hpp"

class DateFactory : public IFactory<t_date, std::string>
{
	private:
		ADateChecker *_checker;
		void initDate(t_date &date, std::string value) const;

	public:
		DateFactory();
		virtual ~DateFactory();
		DateFactory(DateFactory const &src);
		DateFactory& operator=(DateFactory const &src);
		virtual t_date getProduct(std::string value, ...) const;
};

