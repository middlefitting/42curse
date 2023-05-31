#ifndef CHECKER_HPP
# define CHECKER_HPP

#include <iostream>
#include <iomanip>
#include <fstream>

class Checker {
	public:
		Checker(void);
		~Checker(void);
		void	argc_check(int& argc) const;
		void	open_check(std::ifstream& file) const;
		void	open_check(std::ofstream& file) const;
		void	failCheck(std::ifstream& file) const;
		void	failCheck(std::ofstream& file) const;
};

#endif
