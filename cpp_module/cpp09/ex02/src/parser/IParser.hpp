#pragma once

#include <string>
#include "../exception/ExceptionThrower.hpp"

template<typename T>
class IParser
{

	public:
		virtual ~IParser() {}
		virtual T parse(int argc, char **argv) const = 0;
};
