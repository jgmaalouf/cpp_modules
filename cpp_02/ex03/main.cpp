#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main ()
{
	Point a(0.0f, 0.0f);
	Point b(20.0f, 0.0f);
	Point c(10.0f, 30.0f);
	Point p(10.0f, 15.0f);

	if (bsp(a, b, c, p))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;
}