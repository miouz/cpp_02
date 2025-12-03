#ifndef POINT_HPP_
#define POINT_HPP_

#include "Fixed.hpp"

class Point
{
	const Fixed	x_;
	const Fixed	y_;

	public:
	Point();
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	Point	operator-(const Point& other) const;
	Point	operator+(const Point& other) const;
	Fixed	cross(const Point& other) const;
	Fixed	signedPosToVec(const Point& P1, const Point& P2) const;
};

bool bsp( Point const a, Point const b,
		 Point const c, Point const point);
#endif // !POINT_HPP_
