#include "DequeParser.hpp"

DequeParser::DequeParser()
{
	_checker = new RateChecker();
}

DequeParser::~DequeParser()
{
	delete _checker;
}

DequeParser::DequeParser(DequeParser const &src)
{
	(void) src;
	_checker = new RateChecker();
}

DequeParser& DequeParser::operator=(DequeParser const &src)
{
	if (this == &src)
		return *this;
	delete this;
	new (this) DequeParser(src);
	return *this;
}

std::deque<int> DequeParser::parse(int argc, char **argv) const
{
	std::deque<int> result;

	for (int i = 1; i < argc; i ++)
	{
		std::deque<std::string> tmp = split(argv[i], ' ');
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

std::deque<std::string> DequeParser::split(const char *str, char delimiter) const
{
    std::deque<std::string> result;
    std::string token;
    std::istringstream iss(str);

    while (std::getline(iss, token, delimiter))
	{
		if (token != "")
	        result.push_back(token);
    }
    return result;
}
