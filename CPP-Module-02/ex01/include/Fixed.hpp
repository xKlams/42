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
		int getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif
