#pragma once

#include <iostream>
#include <vector>
#include "point.hpp"
#include "shape.hpp"
#include "polygon.hpp"

class PointCloud : private Polygon, virtual public Shape {
    private:
        std::vector<Point> points;
        void setHull();
    public:
        PointCloud(size_t points = 0);
        PointCloud(const std::vector<Point>& points);
        PointCloud(const PointCloud& reg);
        virtual ~PointCloud() = default;

        using Polygon::getAnchor;
        using Polygon::getVertices;
        using Polygon::vCount;

        const std::vector<Point>& getPoints() const;
        
        using Polygon::area;
        using Polygon::perimeter;

        using Polygon::intersects;

        using Polygon::contains;

        PointCloud& operator=(const PointCloud& reg);

        friend std::istream& operator>>(std::istream& is, PointCloud& reg);
};