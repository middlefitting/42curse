#ifndef FIXED_CPP
# define FIXED_CPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
	static const int _number_of_fractional_bits;
	int raw_bits;
	int getBitMasks(void) const;

	public:
	Fixed(void);
	Fixed(int value);
	Fixed(float value);
	Fixed(Fixed const &fixed);
	Fixed& operator=(Fixed const &fixed);
	~Fixed(void);
	int getRawBits(void) const;
	float toFloat(void) const;
	int toInt(void) const;
	void setRawBits(int const raw_bits);
};

std::ostream& operator<<(std::ostream &out_stream, Fixed const &fixed);
#endif
