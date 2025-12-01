#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int	main()
{
	Point a(-2382473892748913248,0);
	Point b(4.34, 0);
	Point c(0, 4);
	Point p(1, 2.567309789686979890890809980696757879889890);

	std::cout << std::boolalpha << bsp(a, c, b, p)<< std::endl;	
	std::cout << std::boolalpha << bsp(a, p, b, c)<< std::endl;	
	return (0);
}
