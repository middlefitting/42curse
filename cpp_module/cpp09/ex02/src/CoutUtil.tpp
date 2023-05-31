#pragma once

/*Regular Message*/
template<typename T>
void CoutUtil::regularCout(T msg) {
	std::cout << msg << std::endl;
}

template<typename T>
void CoutUtil::regularCoutNoEndl(T msg) {
	std::cout << msg;
}


/*Warning Message*/
template<typename T>
void CoutUtil::warningCout(T msg) {
	std::cout << "\033[33m" << msg << "\033[0m" << std::endl;
}

template<typename T>
void CoutUtil::warningCoutNoEndl(T msg) {
	std::cout << "\033[33m" << msg << "\033[0m";
}


/*Info Message*/
template<typename T>
void CoutUtil::infoCout(T msg) {
	std::cout << "\033[36m" << msg << "\033[0m" << std::endl;
}

template<typename T>
void CoutUtil::infoCoutNoEndl(T msg) {
	std::cout << "\033[36m" << msg << "\033[0m";
}


/*Error Message*/
template<typename T>
void CoutUtil::errorCout(T msg) {
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

template<typename T>
void CoutUtil::errorCoutNoEndl(T msg) {
	std::cout << "\033[31m" << msg << "\033[0m";
}
