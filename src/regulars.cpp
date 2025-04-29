#include "regulars.hpp"
#include "math2d.hpp"

Regular::Regular(size_t vertices, double radius, Point center, double phi)
: Polygon(vertices), center(center), r(radius), phi(phi)
{
    if(vertices == 1 || vertices == 2)
        throw "no shape";
    
    calculateVertices();
}

Regular::Regular(const Regular& reg)
: Regular(reg.vCount(), reg.r, reg.center, reg.phi)
{}


void Regular::calculateVertices()
{
    if(vCount() == 0)
        return;
    
    double step = 360.0/vCount();
    double alpha = phi;
    
    for(size_t i = 0; i < vCount(); i++)
    {
        this->vertices[i] = {center.x+cos(step*i + alpha)*r,
                             center.y+sin(step*i + alpha)*r};
    }
}


const Point& Regular::getAnchor() const
{ return center; }


double Regular::area() const
{
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
    double x = p.x - center.x;
    double y = p.y - center.y;

    return x*x + y*y <= r*r; 
}


bool Regular::contains(const Shape& s) const
{
    if(vCount() != 0)
        return Polygon::contains(s);

    // circle + circle
    if(s.vCount() == 0)
    {
        double dist = center|s.getAnchor();
        const Regular* p = dynamic_cast<const Regular*>(&s);
        
        return dist <= r && r-dist >= p->r;
    }

    // circle + poly
    for(auto& x : s.getVertices())
    {
        if((center|x) > r)
            return false;
    }
    return true;
}


Regular& Regular::operator=(const Regular& reg)
{
    if(this == &reg)
        return *this;

    center = reg.center;
    r = reg.r;
    phi = reg.phi;
    Polygon::operator=(reg);

    return *this;
}


void Regular::read(std::istream& is) {
    size_t vcount;
    is >> vcount;
    if(vcount == 1 || vcount == 2)
        throw "no shape";
    
    
    double radius, phi;
    Point center;
    is >> radius >> center >> phi;
    
    this->vertices.resize(vcount);
    this->calculateVertices();
}


void Regular::print(std::ostream& os) const {
    
}
