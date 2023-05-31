#include "RPN.hpp"

RPN::RPN()
{
	_func_ptr[0] = &RPN::plus;
	_func_ptr[1] = &RPN::minus;
	_func_ptr[2] = &RPN::multifly;
	_func_ptr[3] = &RPN::divide;
}

RPN::RPN(const RPN& src)
{
	_stack = std::stack<int>(src._stack);
	_func_ptr[0] = &RPN::plus;
	_func_ptr[1] = &RPN::minus;
	_func_ptr[2] = &RPN::multifly;
	_func_ptr[3] = &RPN::divide;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN &src)
{
	if (&src == this)
		return *this;
	delete this;
	new (this) RPN(src);
	return *this;
}

void RPN::parse(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		int ind = 0;
		while(argv[i][ind])
		{
			calc(argv[i][ind]);
			ind++;
		}
	}
	coutResult();
}

void RPN::calc(char element)
{
	std::string operators = "+-*/";
	if (std::isspace(element))
		return;
	else if (std::isdigit(element))
		_stack.push(element - '0');
	else if (operators.find(element) != std::string::npos)
		(this->*_func_ptr[operators.find(element)])();
	else
		error();
}

void RPN::plus()
{
	if (_stack.size() < 2)
		error();
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(a + b);
}

void RPN::minus()
{
	if (_stack.size() < 2)
		error();
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(b - a);
}

void RPN::multifly()
{
	if (_stack.size() < 2)
		error();
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(a * b);
}

void RPN::divide()
{
	if (_stack.size() < 2)
		error();
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	if (a == 0)
		error();
	_stack.push(b / a);
}

void RPN::error()
{
	CoutUtil::regularCout("Error");
	std::exit(1);
}

void RPN::coutResult()
{
	if (_stack.size() != 1)
		error();
	CoutUtil::regularCout(std::to_string(_stack.top()));
}
