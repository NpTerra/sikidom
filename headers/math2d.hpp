#pragma once

#include "point.hpp"

namespace math2d {
    
    enum DIRECTION {
        CENTER = 0,
        LEFT = 1,
        RIGHT = -1,
        BACK = -2,
        FRONT = 2
    };
    
    template<typename T>
    int cmp(T x, T y);

    inline double orient(const Point& a, const Point& b, const Point& c)
    {
        return (b-a)%(c-a);
    }

    inline DIRECTION leaning(const Point& a, const Point& b, const Point& c)
    {
        double o = orient(a, b, c);
        if(o > 0) return LEFT;
        if(o < 0) return RIGHT;
        
        return CENTER;
    }

    inline bool collinear(const Point& a, const Point& b, const Point& c)
    {
        return orient(a, b, c) == 0;
    }

    bool isPointOnSegment(const Point& p, const Point& a, const Point& b);

    bool doIntersect(const Point& a, const Point& b,
                    const Point& c, const Point& d);

    bool doLineSegmentAndCircleIntersect(const Point& s1, const Point& s2,
                                        const Point& center, double r);
}