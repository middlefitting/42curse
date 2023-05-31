#pragma once

#include <algorithm>
#include "CoutUtil.hpp"

// template<typename T>
// bool easyfind(const T& container, const int n)
// {
//     if (std::find(container.begin(), container.end(), n) != container.end())
//         return true;
//     return false;
// }

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::runtime_error("Not found");
	return iter;
}
