#include "Point.hpp"
#include "Fixed.hpp"

Fixed ft_abs(Fixed input)
{
	if (input < Fixed(0))
		return (input * Fixed(-1));
	return (input);
}

Fixed findArea(Point const a, Point const b, Point const c)
{
	Fixed area;

	// Equation to find area of a triangle:
	//	area = (( x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2) ) / 2.0)

	area = ft_abs((
			a.getX() * ( b.getY() - c.getY() )
			+ b.getX() * ( c.getY() - a.getY() )
			+ c.getX() * ( a.getY() - b.getY() )
		) / Fixed(2.0f));
	
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = findArea(a, b, c);
	Fixed pbcArea = findArea(point, b, c);
	Fixed pacArea = findArea(point, a, c);
	Fixed pabArea = findArea(point, a, b);

	if (abcArea == pbcArea + pacArea + pabArea)
		return true;
	return false;
}
