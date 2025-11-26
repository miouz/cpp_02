#include "Fixed.hpp"

const int Fixed::frac_ = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	value_ = 0;	
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
	this->value_ = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return value_;
}


void	Fixed::setRawBits(int const raw)
{
	value_ = raw;
}
