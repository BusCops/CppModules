#include "point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float AreaA = Point::CalculateArea(point, a, c);
	float AreaB = Point::CalculateArea(point, a, b);
	float AreaC = Point::CalculateArea(point, b, c);
	float AreaO = Point::CalculateArea(a, b, c);
	float Total = AreaA + AreaB + AreaC;
	if (AreaA == 0 || AreaB == 0 || AreaC == 0)
		return false;
	if (Total <= AreaO)
		return true;
	return false;
}
