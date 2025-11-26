#include "Fixed.hpp"


const int Fixed::frac_ = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
}
