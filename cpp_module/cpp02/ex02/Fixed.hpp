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
	Fixed& operator+(Fixed const &fixed);
	Fixed& operator-(Fixed const &fixed);
	Fixed& operator*(Fixed const &fixed);
	Fixed& operator/(Fixed const &fixed);

	Fixed& operator++(void);
	Fixed& operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	bool operator>(Fixed const &fixed);
	bool operator<(Fixed const &fixed);
	bool operator>=(Fixed const &fixed);
	bool operator<=(Fixed const &fixed);
	bool operator==(Fixed const &fixed);
	bool operator!=(Fixed const &fixed);

	~Fixed(void);
	int getRawBits(void) const;
	float toFloat(void) const;
	int toInt(void) const;
	void setRawBits(int const raw_bits);

	static const Fixed& max(Fixed const &a, Fixed const &b);
	static const Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static const Fixed& min(Fixed &a, Fixed &b);
};

std::ostream& operator<<(std::ostream &out_stream, Fixed const &fixed);
#endif
