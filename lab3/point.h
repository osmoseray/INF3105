#if !defined(__POINT_H__)
#define __POINT_H__

#include <iostream>

class Point {
  public:
    Point(double x=0, double y=0);
    Point(const Point&);

    double distance(const Point&) const;

  private:
    double x;
    double y;

    friend std::ostream& operator << (std::ostream&, const Point&);
    friend std::istream& operator >> (std::istream&, Point&);
};

#endif

