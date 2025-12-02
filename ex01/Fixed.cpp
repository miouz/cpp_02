#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::frac_ = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	rawBits_ = 0;	
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return *this;
	this->rawBits_ = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return rawBits_;
}


void	Fixed::setRawBits(int const rawBits)
{
	rawBits_ = rawBits;
}


Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	int rawBits = value * (1<<frac_);
	setRawBits(rawBits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	int rawBits = roundf(value * (1<<frac_));
	setRawBits(rawBits);
}
	
float	Fixed::toFloat(void) const
{
	return static_cast<float>(rawBits_) / (1<<frac_);
}

int		Fixed::toInt(void) const
{
	return rawBits_ >> frac_;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}
