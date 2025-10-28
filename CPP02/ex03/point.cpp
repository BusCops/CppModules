#include "point.hpp"

Point::Point()
:x(0), y(0)
{
}

Point::Point(const float& x, const float& y)
:x(x), y(y)
{
}

Point& Point::operator=(const Point&)
{
	return *this;
}

Point::Point(const Point& other)
: x(other.x), y(other.y)
{
}

float Point::GetX()const
{
	std::cout << "debug x " << x.toFloat() << std::endl;
	return x.toFloat();
}

float Point::GetY()const
{
	std::cout << "debug y " << y.toFloat() << std::endl;
	return y.toFloat();
}

Point::~Point()
{
}

float Point::CalculateArea(const Point &a, const Point &b, const Point &c)
{
	Fixed total = a.x * (b.y - c.y);
	total = total + (b.x * (c.y - a.y));
	total = total + (c.x * (a.y - b.y));
	float Total = total.toFloat() / 2.0f;
	if (Total < 0)
    	return -Total;
	return Total;
}