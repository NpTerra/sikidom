#include "point.hpp"
#include <limits>

const double Point::MAXVAL = std::numeric_limits<double>::max();
const double Point::MINVAL = std::numeric_limits<double>::min();

Point::Point(double x, double y) : px(x), py(y){}

double Point::x() const { return px; }
double Point::y() const { return py; }

bool Point::operator==(const Point& p) const {
    return px==p.px && py==p.py;
}

Point& Point::operator=(const Point& p) {
    px = p.px;
    py = p.py;
    return *this;
}

Point Point::operator+(const Point& p) const
{
    return Point(px+p.px, py+p.py);
}

Point Point::operator-(const Point& p) const
{
    return Point(px-p.px, py-p.py);
}

double Point::operator|(const Point& p) const {
    double dx = px-p.px;
    double dy = py-p.py;
    return sqrt(dx*dx + dy*dy);
}

/**
 * Dot Product
 */
double Point::operator*(const Point& p) const {
    return px*p.px + py*p.py;
}

/**
 * Cross Product
 */
double Point::operator%(const Point& p) const {
    return px*p.py - py*p.px;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.px >> p.py;
    return is;
}