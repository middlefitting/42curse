#pragma once

#include <string>

template<typename T, typename Arg>
class IFactory
{
	public:
		virtual ~IFactory() {}
		virtual T getProduct(Arg value, ...) const = 0;
};
