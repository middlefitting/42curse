#include "CoutUtil.hpp"
#include "Serializer.hpp"

int main()
{
	CoutUtil::infoCout("===== Start =====");
	CoutUtil::infoCout("===== Serialize =====");
	Data data;
	data.data = 42;
	CoutUtil::regularCout("data.data = " + std::to_string(data.data));
	std::cout << "ptr = " << &data << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	CoutUtil::regularCout("raw = " + std::to_string(raw));

	CoutUtil::infoCout("===== Deserialize =====");
	Data* deptr = Serializer::deserialize(raw);
	CoutUtil::regularCout("deptr->data = " + std::to_string(deptr->data));
	std::cout << "deptr = " << deptr << std::endl;
	CoutUtil::infoCout("===== End =====");
	return 0;
}
