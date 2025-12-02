#include "Fixed.hpp"
#include <cmath>
#include <climits>
#include <iostream>

const int Fixed::frac_ = 8;

Fixed::Fixed(void)
{
	rawBits_ = 0;
}
Fixed::~Fixed(void){}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
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
	int rawBits = value * (1<<frac_);
	setRawBits(rawBits);
}

Fixed::Fixed(const float value)
{
	int rawBits = roundf(value * (1<<frac_));
	setRawBits(rawBits);
}
	
float	Fixed::toFloat(void) const
{
	return static_cast<float>(rawBits_) /(1<<frac_);
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

	//for multiply overflow protection
	temp = static_cast<long>(this->rawBits_) * static_cast<long>(other.getRawBits());
	temp = temp / (1<<frac_);
	if (temp > INT_MAX || temp < INT_MIN)
		std::cerr<< "operator * causes overflow, result incorrect\n";
	result.setRawBits(static_cast<int32_t>(temp));
	return result;
}

Fixed	Fixed::operator/(const Fixed& other)const
{
	long temp;
	Fixed result;

	//for multiply overflow protection
	temp = static_cast<long>(this->rawBits_) * (1<<frac_);
	temp = temp / other.getRawBits();
	if (temp > INT_MAX || temp < INT_MIN)
		std::cerr<< "operator / causes overflow, result incorrect\n";
	result.setRawBits(static_cast<int32_t>(temp));
	return result;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->rawBits_++;
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->rawBits_--;
	return tmp;
}

Fixed&	Fixed::operator++()
{
	this->rawBits_++;
	return *this;
}

Fixed&	Fixed::operator--()
{
	this->rawBits_--;
	return *this;
}


Fixed&	Fixed::min(Fixed& a, Fixed&b)
{
	return (a < b? a:b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed&b)
{
	return (a < b? a:b);
}

Fixed&	Fixed::max(Fixed& a, Fixed&b)
{
	return (a > b? a:b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed&b)
{
	return (a > b? a:b);
}
