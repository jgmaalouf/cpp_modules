#include "Point.hpp"

Point::Point() : x_(Fixed(0)), y_(Fixed(0))
{
}

Point::Point(const float x, const float y) : x_(x), y_(y)
{
}

Point::Point( const Point& point )
	:x_(point.x_), y_(point.y_)
{
}

Point& Point::operator=(const Point& point)
{
	(void)point;
	std::cout << "It's illogical to assign anything to const values. Hence the copy assignment operator cannot be implemented!" << std::endl;
	return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return x_;
}

Fixed Point::getY() const
{
	return y_;
}
