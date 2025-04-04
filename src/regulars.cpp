#include "regulars.hpp"
#include "polygon.hpp"
#include "point.hpp"
#include "math2d.hpp"

void Regular::calculateVertices() {
    if(vCount() == 0)
        return;
    
    double step = 360.0/vCount();
    double alpha = phi;
    
    for(size_t i = 0; i < vCount(); i++)
    {
        this->vertices[i] = {center.x()+cos(alpha)*r,
                             center.y()+sin(alpha)*r};
    }
}

Regular::Regular(size_t vertices, double radius, Point center, double phi)
: Polygon(vertices), center(center), r(radius), phi(phi) {
    if(vertices == 1 || vertices == 2)
        throw "no shape";
    
    calculateVertices();
}


double Regular::area() const {
    if(vCount() == 0)
        return r*r*M_PI;
    
    return Polygon::area();
}


bool Regular::intersects(const Point& a, const Point& b) const
{
    if(vCount() != 0)
        return Polygon::intersects(a, b);
    
    // circle
    return math2d::doLineSegmentAndCircleIntersect(a, b, center, r);
}


bool Regular::contains(const Point& p) const
{
    if(vCount() != 0)
        return Polygon::contains(p);
    
    // circle
    double x = p.x() - center.x();
    double y = p.y() - center.y();

    return x*x + y*y <= r*r; 
}


bool Regular::contains(const Shape& s) const
{
    if(vCount() != 0)
        return Polygon::contains(s);

    // circle + circle
    if(s.vCount() == 0)
    {

    }

    // circle + poly
}


Regular& Regular::operator=(const Regular& reg) {
    if(this == &reg)
        return *this;

    center = reg.center;
    r = reg.r;
    phi = reg.phi;
    vertices = reg.vertices;

    return *this;
}

std::istream& operator>>(std::istream& is, Regular& reg) {
    size_t vcount;
    is >> vcount;
    if(vcount == 1 || vcount == 2)
        throw "no shape";
    
    
    double radius, phi;
    Point center;
    is >> radius >> center >> phi;
    
    reg.vertices.resize(vcount);
    reg.calculateVertices();

    return is;
}