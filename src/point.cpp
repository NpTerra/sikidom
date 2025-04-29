#include <limits>
#include "point.hpp"
#include "math2d.hpp"
#include "memtrace.h"

const double Point::MAXVAL = std::numeric_limits<double>::max();
const double Point::MINVAL = std::numeric_limits<double>::min();

Point::Point(double x, double y) : x(x), y(y){}

int Point::cmp(const Point& p) const { if (int t = math2d::cmp(x,p.x)) return t; return math2d::cmp(y,p.y); }

bool Point::operator==(const Point& p) const {
    return x==p.x && y==p.y;
}

Point& Point::operator=(const Point& p) {
    x = p.x;
    y = p.y;
    return *this;
}

Point Point::operator+(const Point& p) const
{
    return Point(x+p.x, y+p.y);
}

Point Point::operator-(const Point& p) const
{
    return Point(x-p.x, y-p.y);
}

double Point::operator|(const Point& p) const {
    double dx = x-p.x;
    double dy = y-p.y;
    return sqrt(dx*dx + dy*dy);
}

/**
 * Dot Product
 */
double Point::operator*(const Point& p) const {
    return x*p.x + y*p.y;
}

/**
 * Cross Product
 */
double Point::operator%(const Point& p) const {
    return x*p.y - y*p.x;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
    os << p.x << " " << p.y;
    return os;
}

#define Comp(x) bool Point::operator x (Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
#undef Comp
