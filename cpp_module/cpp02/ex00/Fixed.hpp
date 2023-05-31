#ifndef FIXED_CPP
# define FIXED_CPP

#include <iostream>

class Fixed {
	private:
	static const int _number_of_fractional_bits;
	int raw_bits;

	public:
	Fixed(void);
	Fixed(Fixed const &fixed);
	Fixed& operator=(Fixed const &fixed);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw_bits);
};
#endif
