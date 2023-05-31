#include "Span.hpp"
#include "CoutUtil.hpp"

int main()
{
	CoutUtil::infoCout("Subject main test");
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	CoutUtil::infoCout("My main test: span functions");
	{
		Span span(10);
		span.addNumber(2);
		span.addNumber(5);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(100);
		span.addNumber(200);
		span.addNumber(3000000);
		span.addNumber(400);
		span.addNumber(1000);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	CoutUtil::infoCout("My main test: span functions");
	{
		Span span(3);
		try
		{
			span.longestSpan();
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
		try
		{
			span.shortestSpan();
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}

		span.addNumber(2);
		try
		{
			span.longestSpan();
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
		try
		{
			span.shortestSpan();
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}

		span.addNumber(-1);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;

		span.addNumber(1);
		try
		{
			span.addNumber(3);
		}
		catch(const std::exception& e)
		{
			CoutUtil::errorCout(e.what());
		}
	}
	CoutUtil::infoCout("My main test: big");
	{
		std::srand(time(NULL));
		Span span(100000);
		span.addRandNumbers();
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
}
