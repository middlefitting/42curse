#include "Serializer.hpp"

/*Default*/
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& src) { *this = src; }
Serializer::~Serializer() {}
Serializer&	Serializer::operator=(const Serializer& src) { (void)src; return *this; }

/*Function*/
// 포인터 타입끼리 변환을 허용
// 정수형을 포인터로 변환할수도 있다.
uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
