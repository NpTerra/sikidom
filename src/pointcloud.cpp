#include <algorithm>
#include "pointcloud.hpp"
#include "math2d.hpp"

#include "memtrace.h"

PointCloud::PointCloud(size_t points)
: Shape("Pontfelhő"), Polygon(0), points(points)
{}

PointCloud::PointCloud(const Vector<Point>& points)
: Shape("Pontfelhő"), Polygon(0), points(points)
{ setHull(); }

PointCloud::PointCloud(const PointCloud& pc)
: Shape("Pontfelhő"), Polygon(pc), points(pc.points)
{}


void PointCloud::setHull()
{
    Vector<Point> temp = points;
    std::sort(temp.begin(), temp.end());
    vertices.push_back(temp[0]);
    vertices.push_back(temp[1]);
    vertices.push_back(temp[2]);

    for(size_t i = 3; i < temp.size(); i++)
    {
        if(math2d::leaning(vertices[vertices.size()-2], vertices.back(), temp[i]) == math2d::LEFT)
        {
            vertices.push_back(temp[i]);
        }
        else
        {
            vertices.back() = temp[i];
        }
    }
}

Shape* PointCloud::clone() const {
    return new PointCloud(*this);
} 


const Vector<Point>& PointCloud::getPoints() const
{ return points; }


PointCloud& PointCloud::operator=(const PointCloud& pc)
{
    Polygon::operator=(pc);
    points = pc.points;
    
    return *this;
}


void PointCloud::read(std::istream& is) {
    size_t vcount;
    is >> vcount;

    this->vertices.clear();
    this->points.resize(vcount);

    for(auto& x : this->points)
        is >> x;
    this->setHull();
}


void PointCloud::print(std::ostream& os) const {
    os << points.size();
    for(auto& x : points)
        os << " " << x;
    os << std::endl;
}
