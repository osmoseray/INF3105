/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#include <assert.h>
#include <math.h>
#include "point.h"

Point::Point(double x_, double y_) 
  : x(x_), y(y_)
{
}

Point::Point(const Point& point)
  : x(point.x), y(point.y) 
{
}

double Point::distance(const Point& point) const {
  // À compléter.
  return 0;
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

