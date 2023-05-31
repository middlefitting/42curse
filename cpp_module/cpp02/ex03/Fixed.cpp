#include "Fixed.hpp"

const int Fixed::_number_of_fractional_bits = 8;

Fixed::Fixed(void) {
	this->raw_bits = 0;
}

Fixed::Fixed(int value) {
	this->raw_bits = value << this->_number_of_fractional_bits;
}

Fixed::Fixed(float value) {
	this->raw_bits = roundf(value * this->getBitMasks());
}

Fixed::Fixed(Fixed const &fixed) {
	*this = fixed;
}

Fixed& Fixed::operator=(Fixed const &fixed) {
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed& Fixed::operator+(Fixed const &fixed) {
	this->setRawBits(this->getRawBits() + fixed.getRawBits());
	return (*this);
}

Fixed& Fixed::operator-(Fixed const &fixed) {
	this->setRawBits(this->getRawBits() - fixed.getRawBits());
	return (*this);
}

Fixed& Fixed::operator*(Fixed const &fixed) {
	int temp = roundf(this->toFloat() * fixed.toFloat() * this->getBitMasks());

	this->setRawBits(temp);
	return (*this);
}

Fixed& Fixed::operator/(Fixed const &fixed) {
	int temp = roundf((float) this->getRawBits() / (float) fixed.getRawBits() * this->getBitMasks());

	this->setRawBits(temp);
	return (*this);
}

Fixed& Fixed::operator++(void) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed& Fixed::operator--(void) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp;

	temp.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp;

	temp.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

bool Fixed::operator>(Fixed const &fixed) {
	return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(Fixed const &fixed) {
	return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(Fixed const &fixed) {
	return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(Fixed const &fixed) {
	return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(Fixed const &fixed) {
	return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(Fixed const &fixed) {
	return this->getRawBits() != fixed.getRawBits();
}

Fixed::~Fixed(void) {}

int	Fixed::getBitMasks(void) const {
	return (1 << this->_number_of_fractional_bits);
}

int Fixed::getRawBits(void) const {
	return (this->raw_bits);
}

float Fixed::toFloat(void) const {
	return ((float) this->getRawBits() / this->getBitMasks());
}

int	Fixed::toInt(void) const {
	return (this->getRawBits() / this->getBitMasks());
}

void Fixed::setRawBits(int const raw_bits) {
	this->raw_bits = raw_bits;
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}


std::ostream& operator<<(std::ostream &out_stream, Fixed const &fixed) {
	out_stream << fixed.toFloat();
	return out_stream;
}
