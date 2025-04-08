#include <algorithm>
#include "pointcloud.hpp"
#include "math2d.hpp"

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
    std::vector<Point> temp = points;
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


const std::vector<Point>& PointCloud::getPoints() const
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