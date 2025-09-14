#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fx_value;
		static const int stored_bits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &object);
		Fixed &operator=(const Fixed &object);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &COUT, const Fixed &object);

#endif