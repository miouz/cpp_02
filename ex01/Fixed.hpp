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
	//ex01
	Fixed(const int value);
	Fixed(const float value);
	float	toFloat(void) const;
	int		toInt(void) const;
	//end ex01
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

//ex01
std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif // !FIXED_HPP_
