#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b,
		 Point const c, Point const point)
{
	Fixed	p_BA = point.signedPosToVec(b, a);	
	Fixed	p_AC = point.signedPosToVec(a, c);
	Fixed	p_CB = point.signedPosToVec(c, b);

	if ((p_BA < 0 && p_AC < 0 && p_CB < 0)
			|| (p_BA > 0 && p_AC > 0 && p_CB > 0))
		return true;
	return false;
}

