#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fx_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fx_value = value << stored_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	fx_value = roundf(value * (1 << stored_bits));
}

Fixed::Fixed(const Fixed &object)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed &Fixed::operator=(const Fixed &object)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object)
	{
		fx_value = object.fx_value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &COUT, Fixed const &object)
{
	COUT << object.toFloat();
	return COUT;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fx_value;
}

void Fixed::setRawBits( int const raw )
{
	this->fx_value = raw;
}

float Fixed::toFloat() const
{
	return (float)(fx_value) / (1 << stored_bits);
}

int Fixed::toInt() const
{
	return fx_value >> stored_bits;
}
