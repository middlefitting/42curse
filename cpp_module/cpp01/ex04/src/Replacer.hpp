#ifndef REPLACER_HPP
# define REPLACER_HPP

#include <iostream>

class Replacer {
	private:
		Replacer(void);
		~Replacer(void);

	public:
		static std::string replace(std::string str, std::string old_v, std::string new_v);
};
#endif
