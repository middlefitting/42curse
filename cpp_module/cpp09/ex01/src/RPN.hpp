#pragma once

#include <iostream>
#include <string>
#include "CoutUtil.hpp"
#include "stack"

typedef enum e_operater
{
	PLUS,
	MINUS,
	MULTI,
	DIVIDE,
}	e_operater;

class RPN
{
	private:
		std::stack<int> _stack;
		void	(RPN::*_func_ptr[4])(void);

		void calc(char element);
		void error();
		void coutResult();

		void plus();
		void minus();
		void multifly();
		void divide();

	public:
		RPN();
		RPN(const RPN& src);
		virtual ~RPN();
		RPN& operator=(const RPN& src);

		void parse(int argc, char** argv);
};
