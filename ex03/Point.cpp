#include "Point.hpp"

Point::Point(void):
x_(0), y_(0){}

Point::~Point(){}

Point::Point(const float x, const float y):
x_(x), y_(y){}


Point::Point(const Fixed x, const Fixed y):
x_(x), y_(y){}

Point::Point(const Point& other):
x_(other.x_), y_(other.y_){}

Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return *this;
	this->~Point();
	new(this)Point(other.x_, other.y_);
	return *this;
}

Point	Point::operator-(const Point& other) const
{
	Point result(this->x_ - other.x_, this->y_ - other.y_);
	return result;
}

Point	Point::operator+(const Point& other) const
{
	Point	result(this->x_ + other.x_, this->y_ - other.y_);
	return result;
}

Fixed	Point::cross(const Point& other) const
{
	Fixed	result(this->x_ * other.y_ - this->y_ * other.x_);
	return result;
}

/**
 * @brief return a signed Fixed value to determine position of Point *this and vector P1P2
 *
 * @param P1 begin point of vector
 * @param P2 end point of vector
 * @return negatif if right, positif if left, 0 if on the line;
 * 
 */
Fixed	Point::signedPosToVec(const Point& P1, const Point& P2) const
{
	Point vec_P1T(*this - P1);
	Point vec_P1P2(P2 - P1);
	return vec_P1T.cross(vec_P1P2); 
}
