#pragma once

#include <string>
#include "../exception/ExceptionThrower.hpp"

template<typename T>
class IParser
{
	public:
		virtual ~IParser() {}
		virtual T parse(const std::string &value) const = 0;
};
