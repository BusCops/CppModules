#include "point.hpp"

int main(void)
{

	Point a(0, 0);
	Point b(20, 0);
	Point c(6.5628, 5.4360);
	Point x(6.5628, 5.4355);

	std::cout << std::boolalpha << bsp(a, b, c, x) << std::endl;

	return 0;
}