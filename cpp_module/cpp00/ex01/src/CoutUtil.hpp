#pragma once

#include <iostream>

class CoutUtil {
	private:
	CoutUtil();
	virtual ~CoutUtil();
	CoutUtil(CoutUtil const &CoutUtil);
	CoutUtil& operator=(CoutUtil const &CoutUtil);

	public:
	static void regularCout(std::string msg);
	static void warningCout(std::string msg);
	static void infoCout(std::string msg);
	static void errorCout(std::string msg);
	static void infoCoutNoEndl(std::string msg);
};
