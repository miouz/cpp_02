#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
	int	fixed_;
	static const int frac_;

	public:
	Fixed(void);
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);
	~Fixed(void);

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif // !FIXED_HPP_
