#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(void):  _number_value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Integer constructor called" << std::endl;
	this->_number_value = roundf(num  * (1 << this->_fractional_bits));
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_number_value = (int) (roundf(num  * (1 << this->_fractional_bits)));
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return ((float) this->_number_value / ( 1 << this->_fractional_bits));
}

int	Fixed::toInt( void ) const
{
	return (this->_number_value >> this->_fractional_bits);
}

Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_number_value = src.getRawBits();

	return (*this);
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_number_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_number_value = raw;
}

bool Fixed::operator>(const Fixed rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator>=(const Fixed rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<(const Fixed rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator<=(const Fixed rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==(const Fixed rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(const Fixed rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

std::ostream& operator<<(std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}

float Fixed::operator+(const Fixed rhs)
{
	long long temp;

	temp = (long long)this->getRawBits() + (long long)rhs.getRawBits();
	temp = temp >> this->_fractional_bits;
	return ((float)temp / (1 << this->_fractional_bits));
}

float Fixed::operator-(const Fixed rhs)
{
	long long temp;

	temp = (long long)this->getRawBits() - (long long)rhs.getRawBits();
	temp = temp >> this->_fractional_bits;
	return ((float)temp / (1 << this->_fractional_bits));
}

float Fixed::operator*(const Fixed rhs)
{
	long long temp;

	temp = (long long)this->getRawBits() * (long long)rhs.getRawBits();
	temp = temp >> this->_fractional_bits;
	return ((float)temp / (1 << this->_fractional_bits));
}

float Fixed::operator/(const Fixed rhs)
{
	long long temp;

	temp = (long long)this->getRawBits() / (long long)rhs.getRawBits();
	temp = temp >> this->_fractional_bits;
	return ((float)temp / (1 << this->_fractional_bits));
}

Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	output;

	output = *this;
	++(*this);
	return(output);
}

const Fixed& Fixed::min(const Fixed& num_1, const Fixed& num_2)
{
	if (num_1 > num_2)
		return (num_2);
	return (num_1);
}

Fixed& Fixed::min(Fixed& num_1, Fixed& num_2)
{
	if (num_1 > num_2)
		return (num_2);
	return (num_1);
}

const Fixed& Fixed::max(const Fixed& num_1, const Fixed& num_2)
{
	if (num_1 < num_2)
		return (num_2);
	return (num_1);
}
Fixed& Fixed::max(Fixed& num_1, Fixed& num_2)
{
	if (num_1 < num_2)
		return (num_2);
	return (num_1);
}
