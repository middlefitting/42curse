#include "Span.hpp"
#include "algorithm"
#include "iostream"

Span::Span()
{
	_limit = 0;
	_curr_size = 0;
}

Span::Span(unsigned int N)
{
	_limit = N;
	_curr_size = 0;
}

Span::Span(Span const &src)
{
	_limit = src._limit;
	_curr_size = src._curr_size;
	_data = std::priority_queue<int>(src._data);
}

Span& Span::operator=(Span const &src)
{
	if (this == &src)
		return *this;
	this->~Span();
	new (this) Span(src);
	return *this;
}

Span::~Span() {}

void Span::addNumber(int const value)
{
	if (_curr_size == _limit)
		throw std::runtime_error("Span is full");
	_data.push(value);
	_curr_size++;
}

unsigned int Span::shortestSpan(void)
{
	if (_curr_size == 0 || _curr_size == 1)
		throw std::runtime_error("Cannot calculate span");

	std::priority_queue<int> copy = std::priority_queue<int>(_data);
	unsigned int result = std::numeric_limits<unsigned int>::max();

	while (copy.size() > 1)
	{
		int big = copy.top();
		copy.pop();
		int small = copy.top();
		result = std::min(result, (unsigned int)(big - small));
	}
	return result;
}

unsigned int Span::longestSpan(void)
{
	if (_curr_size == 0 || _curr_size == 1)
		throw std::runtime_error("Cannot calculate span");

	std::priority_queue<int> copy = std::priority_queue<int>(_data);
	int biggest = copy.top();
	while (copy.size() > 1)
		copy.pop();
	int smallest = copy.top();
	return (unsigned int)(biggest - smallest);
}

void Span::addRandNumbers()
{
	if (_curr_size == _limit)
		throw std::runtime_error("Span is already full");

	int sign = 1;
	for (unsigned int i = 0; i < _limit - _curr_size; i++)
	{
		sign *= -1;
		_data.push(rand() * sign);
	}
	_curr_size = _limit;
}
