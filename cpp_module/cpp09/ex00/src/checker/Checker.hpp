#pragma once

#include <iostream>
#include "IChecker.hpp"
#include "../exception/ExceptionThrower.hpp"

class Checker : public IChecker
{
	public:
		Checker();
		virtual ~Checker();
		Checker(Checker const &src);
		Checker& operator=(Checker const &src);

		virtual void emptyCheck(std::string value) const;

		virtual void existCheck(std::string value, char c) const;

		virtual void sizeCheck(std::string value, char c) const;

		virtual void positiveNumberCheck(float value) const;

		virtual void largeNumberCheck(float value) const;
};
