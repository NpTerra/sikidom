#pragma once

#include <stddef.h>
#include "point.hpp"

class Shape {
    public:
        virtual ~Shape() = default;

        virtual const Point& getAnchor() const = 0;
        virtual const std::vector<Point>& getVertices() const = 0;
        virtual size_t vCount() const = 0;

        virtual double area() const = 0;
        virtual double perimeter() const = 0;

        virtual bool intersects(const Point& a, const Point& b) const = 0;

        virtual bool contains(const Point& p) const = 0;
        virtual bool contains(const Shape& s) const = 0;
};