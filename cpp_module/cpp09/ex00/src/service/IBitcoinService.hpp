#pragma once

#include <string>

class IBitcoinService
{
	public:
		virtual ~IBitcoinService() {}
		virtual void initDb() const = 0;
		virtual void calc(std::string filename) const = 0;
};
