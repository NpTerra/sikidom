#include "pointcloud.hpp"

PointCloud::PointCloud(size_t points = 0)
: Polygon(0), points(points)
{}

PointCloud::PointCloud(const std::vector<Point>& points)
: Polygon(0), points(points)
{ setHull(); }

PointCloud::PointCloud(const PointCloud& reg)
: Polygon(reg), points(reg.points)
{}


void PointCloud::setHull()
{

}


const std::vector<Point> PointCloud::getPoints() const
{ return points; }


PointCloud& PointCloud::operator=(const PointCloud& reg)
{
    Polygon::operator=(reg);
    points = reg.points;
}


std::istream& operator>>(std::istream& is, PointCloud& reg)
{
    size_t vcount;
    is >> vcount;
    reg.vertices.clear();
    reg.points.resize(vcount);
    for(auto& x : reg.points)
        is >> x;

    return is;
}