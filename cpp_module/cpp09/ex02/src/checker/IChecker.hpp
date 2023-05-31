#pragma once

#include <string>

class IChecker
{
	public:
		virtual ~IChecker() {}
		virtual void emptyCheck(std::string value) const = 0;
		virtual void existCheck(std::string value, char c) const = 0;
		virtual void sizeCheck(std::string value, char c) const = 0;
		virtual void positiveNumberCheck(int value) const = 0;
		virtual void largeNumberCheck(float value) const = 0;
};
