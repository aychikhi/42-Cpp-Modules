#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fx_value;
		static const int stored_bits;
	public:
		Fixed();
		Fixed(Fixed &object);
		Fixed &operator=(const Fixed &object);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif