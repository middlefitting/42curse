#pragma once

#include <iostream>
#include <string>

class CoutUtil {
	private:
	CoutUtil();
	virtual ~CoutUtil();
	CoutUtil(CoutUtil const &CoutUtil);
	CoutUtil& operator=(CoutUtil const &CoutUtil);

	public:
		template<typename T>
		static void regularCout(T msg);

		template<typename T>
		static void regularCoutNoEndl(T msg);

		template<typename T>
		static void warningCout(T msg);

		template<typename T>
		static void warningCoutNoEndl(T msg);

		template<typename T>
		static void infoCout(T msg);

		template<typename T>
		static void infoCoutNoEndl(T msg);

		template<typename T>
		static void errorCout(T msg);

		template<typename T>
		static void errorCoutNoEndl(T msg);
};

#include "CoutUtil.tpp"
