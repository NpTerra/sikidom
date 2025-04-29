#include "polygon.hpp"
#include "math2d.hpp"

Polygon::Polygon(size_t vertices) : vertices(vertices)
{}

Polygon::Polygon(const Vector<Point>& vertices) : vertices(vertices)
{}

Polygon::Polygon(const Polygon& poly) : Polygon(poly.vertices)
{}


const Point& Polygon::getAnchor() const
{ return vertices[0]; }


const Vector<Point>& Polygon::getVertices() const
{ return vertices; };


size_t Polygon::vCount() const
{ return vertices.size(); }


double Polygon::area() const
{
    double ar = 0;
    for(size_t i = 0; i < vCount(); i++)
    {
        const Point& a = vertices[i];
        const Point& b = vertices[(i+1)%vCount()];

        double y = (a.y + b.y) / 2.0;
        double x = a.x - b.x;

        ar += x*y;
    }

    return ar;
}


double Polygon::perimeter() const
{
    double per = 0;
    for(size_t i = 0; i < vCount(); i++)
    {
        const Point& a = vertices[i];
        const Point& b = vertices[(i+1)%vCount()];

        per += a|b;
    }

    return per;
}


bool Polygon::intersects(const Point& a, const Point& b) const
{
    for(size_t i = 0, j; i < vCount(); i++)
    {
        j = (i+1)%vCount();

        if(math2d::doIntersect(a, b, vertices[i], vertices[j]))
            return true;
    }

    return false;
}


bool Polygon::contains(const Point& p) const
{
    Point inf(p.x, Point::MAXVAL);

    size_t intersections = 0;
    for(size_t i = 0, j; i < vCount(); i++)
    {
        j = (i+1)%vCount();

        if(!math2d::isPointOnSegment(p, vertices[i], vertices[j]))
            return true;
        
        if(math2d::doIntersect(p, inf, vertices[i], vertices[j]))
            intersections++;
    }

    return intersections%2 == 1;
}


bool Polygon::contains(const Shape& s) const
{
    if(this == &s)
        return true;
    
    if(!contains(s.getAnchor()))
        return false;
    
    for(size_t i = 0, j; i < vCount(); i++)
    {
        j = (i+1)%vCount();
        if(s.intersects(vertices[i], vertices[j]))
            return false;
        
        for(const Point& p : s.getVertices())
        {
            if(!contains(p))
                return false;
        }
    }

    return true;
}


Polygon& Polygon::operator=(const Polygon& poly)
{
    vertices = poly.vertices;

    return *this;
}


void Polygon::read(std::istream& is) {
    size_t vcount;
    is >> vcount;
    if(vcount <= 2)
        throw "no shape";
    
    this->vertices.resize(vcount);
    for(auto& x : this->vertices)
        is >> x;
}


void Polygon::print(std::ostream& os) const {
    
}
