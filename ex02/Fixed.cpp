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
	int32_t rawBits = value * (1<<8);
	setRawBits(rawBits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	int32_t rawBits = std::roundf(value * (1<<8));
	setRawBits(rawBits);
}
	
float	Fixed::toFloat(void) const
{
	return static_cast<float>(rawBits_) /(1<<8);
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

bool	Fixed::operator>(const Fixed& other)const
{
	return (this->rawBits_ > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other)const
{
	return (this->rawBits_ < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other)const
{
	return (this->rawBits_ >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other)const
{
	return (this->rawBits_ <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other)const
{
	return (this->rawBits_ == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other)const
{
	return (this->rawBits_ != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other)const
{
	Fixed result;
	result.setRawBits(this->rawBits_ + other.rawBits_);
	return result;
}

Fixed	Fixed::operator-(const Fixed& other)const
{
	Fixed result;
	result.setRawBits(this->rawBits_ - other.rawBits_);
	return result;
}

Fixed	Fixed::operator*(const Fixed& other)const
{
	long temp;
	Fixed result;

	//for overflow protection
	temp = static_cast<long>(this->rawBits_) * static_cast<long>(other.getRawBits());
	result.setRawBits(static_cast<int32_t>(temp / (1<<8)));
	return result;
}

Fixed	Fixed::operator/(const Fixed& other)const
{
	long temp;
	Fixed result;

	//for multiply overflow protection
	temp = static_cast<long>(this->rawBits_ * (1<<8));
	result.setRawBits(static_cast<int32_t>(temp / other.getRawBits()));
	return result;
}

Fixed&	Fixed::operator++(int dummy)
{
	this->rawBits_++;
	return *this;
}

Fixed&	Fixed::operator--(int dummy)
{
	this->rawBits_--;
	return *this;
}

Fixed	Fixed::operator++()
{
	Fixed	tmp(*this);

	this->rawBits_++;
	return tmp;
}

Fixed	Fixed::operator--()
{
	Fixed	tmp(*this);

	this->rawBits_--;
	return tmp;
}
