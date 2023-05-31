#pragma once

#include "Checker.hpp"

typedef struct s_date
{
	int year;
	int month;
	int day;
} t_date;

class ADateChecker : public Checker
{
	public:
		virtual ~ADateChecker() {}

		virtual void dateFormCheck(std::string value) const = 0;
		virtual	void numberChecker(std::string value) const = 0;
		virtual void dateValidateChecker(t_date &date, std::string value) const = 0;
};
