#include "Fixed.hpp"
#include <iostream>
int main( void ) {
	std::cout << "------------subject's proposed tests---------------\n";
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "------------subject's proposed tests end---------------\n";
	std::cout << "------------ my tests---------------\n";
std::cout << (a < b? "a < b\n":"wrong\n");
std::cout << (b > a? "b > a\n":"wrong\n");
std::cout <<"a is "<< a << std::endl;
std::cout << a-- << std::endl;
std::cout << "a is "<< a << std::endl;
std::cout << --a << std::endl;
std::cout << --a << std::endl;
return 0;
}
