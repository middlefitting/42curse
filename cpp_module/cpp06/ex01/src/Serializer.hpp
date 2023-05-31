#pragma once

#include <cstdint>

typedef struct sData
{
	int	data;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& src);
		Serializer&	operator=(const Serializer& src);
		~Serializer();

	public :
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
