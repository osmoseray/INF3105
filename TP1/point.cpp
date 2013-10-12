/*
 *Date: 13-09-10

*/


#include <assert.h>
#include <math.h>
#include "point.h"

Point::Point(const Point& point)
  : x(point.x), y(point.y)
{
}

Point::Point(double _x, double _y)
  : x(_x), y(_y)
{
}


double Point::distance(const Point& point) const {
   double carreX=pow((point.x-x),2);
   double carreY=pow((point.y-y),2);
   double dist=sqrt(carreX+carreY);
   return dist;
}


std::ostream& operator << (std::ostream& os, const Point& point) {
  os << "(" << point.x << "," << point.y << ")";
  return os;
}

std::istream& operator >> (std::istream& is, Point& point) {
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


