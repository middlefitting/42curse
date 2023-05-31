#include "Replacer.hpp"

Replacer::Replacer(void) {};

Replacer::~Replacer(void) {};

std::string Replacer::replace(std::string str, std::string old_v, std::string new_v) {
	size_t old_v_l = old_v.length();

	if (old_v == new_v)
		return (str);
	if (old_v_l == 0)
		return (str);
	while (true)
	{
		size_t pos = str.find(old_v);
		if (pos == std::string::npos)
			break;
		str.erase(pos, old_v_l);
		str.insert(pos, new_v);
	}
	return (str);
}
