#include "CoutUtil.hpp"
#include "iter.hpp"

template<typename T>
void printValue(T const &value)
{
	std::cout << value << std::endl;
}

int main()
{
	CoutUtil::infoCout("//////// ITER TEST ////////");
	CoutUtil::infoCout("/** INT TEST **/");
	int intArray[5] = {1, 2, 3, 4, 5};
	iter<int>(intArray, 5, printValue);
	CoutUtil::infoCout("/** STRING TEST **/");
	std::string stringArray[5] = {"HELLO", "WORLD", "!", "CPP07", "ex01"};
	iter<std::string>(stringArray, 5, printValue);
}
