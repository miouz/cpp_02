#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cstdint>

class Fixed
{
	int32_t	rawBits_;
	static const int frac_;

	public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);
	~Fixed(void);

	//getter setter
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;
	//operator overload
	bool	operator>(const Fixed& other)const;
	bool	operator<(const Fixed& other)const;
	bool	operator>=(const Fixed& other)const;
	bool	operator<=(const Fixed& other)const;
	bool	operator==(const Fixed& other)const;
	bool	operator!=(const Fixed& other)const;
	Fixed	operator+(const Fixed& other)const;
	Fixed	operator-(const Fixed& other)const;
	Fixed	operator*(const Fixed& other)const;
	Fixed	operator/(const Fixed& other)const;
	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed&	operator++();
	Fixed&	operator--();
static	Fixed&	min(Fixed& a, Fixed&b);
static	const Fixed&	min(const Fixed& a, const Fixed&b);
static	Fixed&	max(Fixed& a, Fixed&b);
static	const Fixed&	max(const Fixed& a, const Fixed&b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif // !FIXED_HPP_
