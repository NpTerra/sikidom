#pragma once

#include <iostream>
#include "vector.hpp"
#include "point.hpp"
#include "shape.hpp"
#include "polygon.hpp"

class PointCloud : private Polygon, virtual public Shape {
    private:
        Vector<Point> points;
        void setHull();
    public:
        PointCloud(size_t points = 0);
        PointCloud(const Vector<Point>& points);
        PointCloud(const PointCloud& reg);
        virtual ~PointCloud() = default;

        using Polygon::getAnchor;
        using Polygon::getVertices;
        using Polygon::vCount;

        const Vector<Point>& getPoints() const;
        
        using Polygon::area;
        using Polygon::perimeter;

        using Polygon::intersects;

        using Polygon::contains;

        PointCloud& operator=(const PointCloud& reg);

        friend std::istream& operator>>(std::istream& is, PointCloud& reg);
};