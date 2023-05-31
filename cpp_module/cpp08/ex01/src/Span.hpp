#pragma once

#include <iostream>
#include <queue>
#include <deque>

class Span
{
	private:
		std::priority_queue<int> _data;
		unsigned int _limit;
		unsigned int _curr_size;
		Span();
	public:
		~Span();
		Span(unsigned int N);
		Span(Span const &src);
		Span& operator=(Span const &src);

		void addNumber(int const value);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		void addRandNumbers();
};

