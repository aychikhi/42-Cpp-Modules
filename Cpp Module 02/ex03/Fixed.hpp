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
		bool operator==(const Fixed &object) const;
		bool operator<=(const Fixed &object) const;
		bool operator!=(const Fixed &object) const;
		bool operator>=(const Fixed &object) const;	
		bool operator<(const Fixed &object) const;
		bool operator>(const Fixed &object) const;
		Fixed operator+(const Fixed &object) const;
		Fixed operator-(const Fixed &object) const;
		Fixed operator*(const Fixed &object) const;
		Fixed operator/(const Fixed &object) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static Fixed &max(Fixed &object1, Fixed &object2);
		static Fixed &min(Fixed &object1, Fixed &object2);
		static const Fixed &max(const Fixed &object1, const Fixed &object2);
		static const Fixed &min(const Fixed &object1, const Fixed &object2);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &COUT, const Fixed &object);

#endif