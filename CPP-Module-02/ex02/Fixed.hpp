#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
	private:
		int			_number_value;
		static const int	_fractional_bits;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		Fixed &operator=(const Fixed &src);

		float operator+(const Fixed rhs);
		float operator-(const Fixed rhs);
		float operator*(const Fixed rhs);
		float operator/(const Fixed rhs);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static const Fixed& min(const Fixed& num_1, const Fixed& num_2);
		static const Fixed& max(const Fixed& num_1, const Fixed& num_2);
		static Fixed& min(Fixed& num_1, Fixed& num_2);
		static Fixed& max(Fixed& num_1, Fixed& num_2);

		bool operator>(const Fixed rhs) const;
		bool operator<(const Fixed rhs) const;
		bool operator>=(const Fixed rhs) const;
		bool operator<=(const Fixed rhs) const;
		bool operator==(const Fixed rhs) const;
		bool operator!=(const Fixed rhs) const;

		int getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat (void ) const;
		int	toInt( void ) const;
};

std::ostream    &operator<<(std::ostream &os, Fixed const &fixed);

#endif
