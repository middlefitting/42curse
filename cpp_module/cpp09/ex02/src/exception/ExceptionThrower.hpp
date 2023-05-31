#pragma once

#include <string>
#include <iostream>

class ExceptionThrower {
	private:
		ExceptionThrower();
		virtual ~ExceptionThrower();
		ExceptionThrower(ExceptionThrower const &src);
		ExceptionThrower& operator=(ExceptionThrower const &src);

	public:
		class DefaultException : public std::invalid_argument
		{
			public:
				DefaultException();

				virtual const char* what() const throw();
		};
};
