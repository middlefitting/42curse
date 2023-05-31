#pragma once
#include <iostream>
#include "ARateChecker.hpp"
#include "../exception/ExceptionThrower.hpp"

class RateChecker : public ARateChecker
{
	private:
		void signPasser(int &idx, const std::string value) const;
		void digitPasser(int &idx, const std::string value) const;
		void dotPasser(int &idx, const std::string value) const;

		void digitChecker(int &idx, const std::string value) const;
		void nullChecker(int &idx, const std::string value) const;

	public:
		RateChecker();
		virtual ~RateChecker();
		RateChecker(RateChecker const &src);
		RateChecker& operator=(RateChecker const &src);

		virtual void numberCheck(std::string value) const;
		virtual void intCheck(std::string value) const;
};
