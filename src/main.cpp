#include <bits/stdc++.h>
#include "math2d.hpp"

using math2d::doIntersect;
using math2d::isPointOnSegment;
using math2d::orient;
using std::cout;
using std::endl;
using math2d::leaning;

int main() {
    
    
    double r = 1;
    Point c(0,0);

    Point a(1.001,0);
    Point b(10,10);

    cout << math2d::doLineSegmentAndCircleIntersect(a, b, c, r) << endl;

    //std::cout << "Intersect: " << std::boolalpha << doIntersect(a, b, c, d) << std::endl;
    //std::cout << "On segment: " << std::boolalpha << isPointOnSegment(a, c, d) << std::endl;
}
