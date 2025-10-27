#ifndef POINT_HPP
#define POINT_HPP

class Point
{

private :
	int x;
	int y;
public :
	Point();
	Point(int x, int y);
	Point& operator=(const Point& point);
	int GetX()const;
	int GetY()const;

};

#endif