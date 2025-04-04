#include "math2d.hpp"

namespace math2d {
    bool isPointOnSegment(const Point& p, const Point& a, const Point& b)
    {
        if(!collinear(p, a, b))
            return false;
        
        Point min(std::min(a.x(), b.x()), std::min(a.y(), b.y()));
        Point max(std::max(a.x(), b.x()), std::max(a.y(), b.y()));

        return min.x() <= p.x() && p.x() <= max.x() &&
                min.y() <= p.y() && p.y() <= max.y();
    }

    bool doIntersect(const Point& a, const Point& b,
                    const Point& c, const Point& d)
    {
        double o1 = orient(a, b, c);
        double o2 = orient(a, b, d);
        double o3 = orient(c, d, a);
        double o4 = orient(c, d, b);
        
        return (o1 * o2 < 0 && o3 * o4 < 0);
    }

    bool doLineSegmentAndCircleIntersect(const Point& s1, const Point& s2, const Point& center, double r)
    {
        double x_lin = s2.x() - s1.x();
        double x_const = s1.x() - center.x();

        double y_lin = s2.y() - s1.y();
        double y_const = s1.y() - center.y();

        double a = x_lin*x_lin + y_lin*y_lin;
        double hb = x_lin*x_const + y_lin*y_const;
        double c = x_const*x_const + y_const*y_const - r*r;

        return (hb*hb >= a*c &&
            (-hb <= a || c + hb + hb + a <= 0) &&
            (hb <= 0 || c <= 0)
        );
    }
}