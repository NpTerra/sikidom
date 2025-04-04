#include <bits/stdc++.h>
#include "math2d.hpp"
#include "regulars.hpp"

using math2d::doIntersect;
using math2d::isPointOnSegment;
using math2d::orient;
using std::cout;
using std::endl;
using math2d::leaning;

int main() {
    
    Regular a(0, 2.0, {0,0}, 0);
    Regular b(0, 1.0, {1,0}, 0);
    bool c = a.contains(b);

    cout << c << endl;

    //std::cout << "Intersect: " << std::boolalpha << doIntersect(a, b, c, d) << std::endl;
    //std::cout << "On segment: " << std::boolalpha << isPointOnSegment(a, c, d) << std::endl;
}
