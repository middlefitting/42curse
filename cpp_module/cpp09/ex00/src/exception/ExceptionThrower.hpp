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
		class BadInputException : public std::invalid_argument
		{
			public:
				BadInputException(std::string message);

				virtual const char* what() const throw();
		};

		class NotPositiveNumberException : public std::invalid_argument
		{
			public:
				NotPositiveNumberException();

				virtual const char* what() const throw();
		};

		class TooLargeNumberException : public std::invalid_argument
		{
			public:
				TooLargeNumberException();

				virtual const char* what() const throw();
		};

		class DataNotExistException : public std::invalid_argument
		{
			public:
				DataNotExistException();

				virtual const char* what() const throw();
		};


		class FileOpenFailedException : public std::runtime_error
		{
			public:
				FileOpenFailedException();

				virtual const char* what() const throw();
		};

		class FileFailedException : public std::runtime_error
		{
			public:
				FileFailedException();

				virtual const char* what() const throw();
		};

		class InvalidFileException : public std::runtime_error
		{
			public:
				InvalidFileException();

				virtual const char* what() const throw();
		};

		class ArgCheckFailedException : public std::runtime_error
		{
			public:
				ArgCheckFailedException();

				virtual const char* what() const throw();
		};
};
