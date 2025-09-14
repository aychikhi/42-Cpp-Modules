#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	fx_value = 0;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	fx_value = value << stored_bits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	fx_value = roundf(value * (1 << stored_bits));
}

Fixed::Fixed(const Fixed &object)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed &Fixed::operator=(const Fixed &object)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object)
	{
		fx_value = object.fx_value;
	}
	return *this;
}

bool Fixed::operator==(const Fixed &object) const
{
	return this->fx_value == object.fx_value;
}

bool Fixed::operator<=(const Fixed &object) const
{
	return this->fx_value <= object.fx_value;
}

bool Fixed::operator>=(const Fixed &object) const
{
	return this->fx_value >= object.fx_value;
}

bool Fixed::operator>(const Fixed &object) const
{
	return this->fx_value > object.fx_value;
}

bool Fixed::operator<(const Fixed &object) const
{
	return this->fx_value < object.fx_value;
}

bool Fixed::operator!=(const Fixed &object) const
{
	return this->fx_value != object.fx_value;
}

Fixed Fixed::operator+(const Fixed &object) const
{
    Fixed result;
    result.fx_value = this->fx_value + object.fx_value;
    return result;
}

Fixed Fixed::operator-(const Fixed &object) const
{
    Fixed result;
    result.fx_value = this->fx_value - object.fx_value;
    return result;
}

Fixed Fixed::operator*(const Fixed &object) const
{
    Fixed result;
    result.fx_value = (this->fx_value * object.fx_value) >> stored_bits;
    return result;
}

Fixed Fixed::operator/(const Fixed &object) const
{
    Fixed result;
    result.fx_value = (this->fx_value << stored_bits) / object.fx_value;
    return result;
}

Fixed	&Fixed::operator++()
{
	this->fx_value++;
	return *this;
}

Fixed	&Fixed::operator--()
{
	this->fx_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fx_value++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fx_value--;
	return temp;
}

std::ostream &operator<<(std::ostream &COUT, Fixed const &object)
{
	COUT << object.toFloat();
	return COUT;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return fx_value;
}

void Fixed::setRawBits( int const raw )
{
	fx_value = raw;
}

float Fixed::toFloat() const
{
	return (float)(fx_value) / (1 << stored_bits);
}

int Fixed::toInt() const
{
	return fx_value >> stored_bits;
}

Fixed &Fixed::min(Fixed &object1, Fixed &object2)
{
	if (object1.getRawBits() < object2.getRawBits())
		return object1;
	return object2;
}

const Fixed &Fixed::min(const Fixed &object1, const Fixed &object2)
{
	if (object1.getRawBits() < object2.getRawBits())
		return object1;
	return object2;
}

const Fixed &Fixed::max(const Fixed &object1, const Fixed &object2)
{
	if (object1.getRawBits() > object2.getRawBits())
		return object1;
	return object2;
}

Fixed &Fixed::max(Fixed &object1, Fixed &object2)
{
	if (object1.getRawBits() > object2.getRawBits())
		return object1;
	return object2;
}
