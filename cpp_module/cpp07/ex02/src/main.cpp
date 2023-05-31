#include "CoutUtil.hpp"
#include "Array.hpp"

template<typename T>
void printValue(T const &value)
{
	std::cout << value << std::endl;
}

int main()
{
	CoutUtil::infoCout("//////// ITER TEST ////////");
	{
		CoutUtil::infoCout("/** Default Constructer Test **/");
		Array<int> int_array_default;
		try
		{
			int_array_default[0] = 42;
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
	}
	CoutUtil::infoCout("/** Constructer Test **/");
	{
		Array<int> int_array(10);
		try
		{
			for (int i = 0; i < 11; i++)
			{
				std::cout << int_array[i] << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
		int *compare = new int(1);
		std::cout << *compare << std::endl;
		delete compare;
	}

	CoutUtil::infoCout("/** Constructer Test **/");
	{
		Array<int> int_array(10);
		try
		{
			for (int i = 0; i < 11; i++)
			{
				std::cout << int_array[i] << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
		int *compare = new int(1);
		std::cout << *compare << std::endl;
		delete compare;
	}

	CoutUtil::infoCout("/** Copy and assignment operator Test **/");
	{
		Array<int> int_array(10);
		Array<int> int_array_copy(int_array);
		Array<int> int_array_assign;
		int_array_assign = int_array;
	}

	CoutUtil::infoCout("/** Size Test **/");
	{
		Array<int> int_array(10);
		std::cout << int_array.size() << std::endl;
	}
}
