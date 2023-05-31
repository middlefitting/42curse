#pragma once
#include <map>
#include <iostream>
#include "ADateChecker.hpp"
#include "../exception/ExceptionThrower.hpp"

class DateChecker : public ADateChecker
{
	private:
		std::map<int, int> _days_of_month;

		void lengthChecker(std::string value) const;
		void hyphenChecker(std::string value) const;

	public:
		DateChecker();
		virtual ~DateChecker();
		DateChecker(DateChecker const &src);
		DateChecker& operator=(DateChecker const &src);

		virtual void dateFormCheck(std::string value) const;
		virtual void numberChecker(std::string value) const;
		virtual void dateValidateChecker(t_date &date, std::string value) const;


};
