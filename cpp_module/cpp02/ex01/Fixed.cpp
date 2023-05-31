#include "Fixed.hpp"

const int Fixed::_number_of_fractional_bits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->raw_bits = 0;
}

Fixed::Fixed(int value) {
	std::cout << "Int constructor called" << std::endl;
	this->raw_bits = value << this->_number_of_fractional_bits;
}

Fixed::Fixed(float value) {
	std::cout << "Float constructor called" << std::endl;
	this->raw_bits = std::round(value * this->getBitMasks());
}

Fixed::Fixed(Fixed const &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(Fixed const &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

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

std::ostream& operator<<(std::ostream &out_stream, Fixed const &fixed) {
	out_stream << fixed.toFloat();
	return out_stream;
}
