#include "VectorParser.hpp"

VectorParser::VectorParser()
{
	_checker = new RateChecker();
}

VectorParser::~VectorParser()
{
	delete _checker;
}

VectorParser::VectorParser(VectorParser const &src)
{
	(void) src;
	_checker = new RateChecker();
}

VectorParser& VectorParser::operator=(VectorParser const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) VectorParser(src);
	return *this;
}

std::vector<int> VectorParser::parse(int argc, char **argv) const
{
	std::vector<int> result;

	for (int i = 1; i < argc; i ++)
	{
		std::vector<std::string> tmp = split(argv[i], ' ');
		while (tmp.size() > 0)
		{
			_checker->intCheck(tmp.back());
			_checker->positiveNumberCheck(std::atoi(tmp.back().c_str()));
			result.push_back(std::atoi(tmp.back().c_str()));
			tmp.pop_back();
		}
	}
	return result;
}

std::vector<std::string> VectorParser::split(const char *str, char delimiter) const
{
    std::vector<std::string> result;
    std::string token;
    std::istringstream iss(str);

    while (std::getline(iss, token, delimiter))
	{
		if (token != "")
	        result.push_back(token);
    }
    return result;
}
