/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#if !defined(_POINT_H_)
#define _POINT_H_

#include <iostream>

class Point {
  public:
    Point(double x_=0, double y_=0);
    Point(const Point&);

    double distance(const Point&) const;

  private:
    double x;
    double y;

    friend std::istream& operator >> (std::istream&, Point&);
    friend std::ostream& operator << (std::ostream&, const Point&);
};

#endif

