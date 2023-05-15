#include <cmath>
#include "Point.hpp"

using namespace std;
using namespace ariel;

Point::Point() : _x(0.0), _y(0.0) {}

Point::Point(double pt_x, double pt_y) : _x(pt_x), _y(pt_y) {}

double Point::getX() const
{
	return _x;
}

double Point::getY() const
{
	return _y;
}

double Point::distance(Point other) const
{
	return sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2));
}

string Point::print() const
{
	return "(" + to_string(_x) + ", " + to_string(_y) + ")";
}

Point Point::moveTowards(const Point &curr, const Point &other, const double dist)
{
	if (dist < 0)
		throw invalid_argument("Distance cannot be negative!");
	
	double d = curr.distance(other);

	if (d <= dist)
		return other;

	return Point((curr._x + (dist * (other._x - curr._x) / d)), (curr._y + (dist * (other._y - curr._y) / d)));
}