#include <assert.h>
#include <math.h>
#include "point.h"

Point::Point(double _x, double _y) 
  : x(_x), y(_y)
{
}

Point::Point(const Point& point)
  : x(point.x), y(point.y) 
{
}

double Point::distance(const Point& point) const {
    return sqrt(pow((x-point.x), 2) + pow((y-point.y),2));
}

ostream& operator << (ostream& os, const Point& point) {
    os << "(" << point.x << "," << point.y << ")";
    return os;
}

istream& operator >> (istream& is, Point& point) {
    char po, vir, pf;
    is >> po;
    if(is){
        is >> point.x >> vir >> point.y >> pf;
        assert(po=='(');
        assert(vir==',');
        assert(pf==')');
    }
    return is;
}
