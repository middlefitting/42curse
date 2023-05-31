#pragma once

#include "Checker.hpp"

class ABitcoinServiceChecker : public Checker
{
	public:
		virtual ~ABitcoinServiceChecker() {}

		virtual void	fileHeadCheck(std::ifstream& file, std::string value) const = 0;
		virtual void	fileOpenCheck(std::ifstream& file) const = 0;
		virtual void	fileFailCheck(std::ifstream& file) const = 0;
};
