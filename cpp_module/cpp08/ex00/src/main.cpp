#include "easyfind.hpp"
#include "CoutUtil.hpp"
#include <vector>

int main()
{
	CoutUtil::infoCout("////////////** TEST **////////////");
	CoutUtil::infoCout("/** Exist **");
	std::vector<int> v;
	v.push_back(1);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(25);
	v.push_back(5);
	std::cout << v[0] << std::endl;
	std::cout << ::easyfind(v, 5)[0] << std::endl;

	CoutUtil::infoCout("/** Not Exist **");
	try
	{
		::easyfind(v, 45);
	}
	catch(const std::exception& e)
	{
		CoutUtil::errorCout(e.what());
	}

	return 0;
}
