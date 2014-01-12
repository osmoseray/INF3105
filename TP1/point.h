#if !defined(__POINT_H__)
#define __POINT_H__

#include <iostream>
using namespace std;

class Point {
    public:
        Point(double x=0, double y=0);
        Point(const Point&);
        
        //Calcule et retourne la distance entre deux points.
        double distance(const Point&) const;

    private:
        double x;
        double y;

    friend ostream& operator << (ostream&, const Point&);
    friend istream& operator >> (istream&, Point&);
};

#endif
