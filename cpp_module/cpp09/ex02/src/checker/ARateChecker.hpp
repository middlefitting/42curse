#pragma once

#include "Checker.hpp"

class ARateChecker : public Checker
{
	public:
		virtual ~ARateChecker() {}

		virtual void numberCheck(std::string value) const = 0;
		virtual void intCheck(std::string value) const = 0;
};
