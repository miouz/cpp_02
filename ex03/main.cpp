#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int	main()
{
	Point a(-4.2,0);
	Point b(4.34, 0);
	Point c(0, 4);
	Point p(1, 2.56730);

	std::cout << std::boolalpha << bsp(a, c, b, p)<< std::endl;	
	std::cout << std::boolalpha << bsp(a, p, b, c)<< std::endl;	
	return (0);
}
