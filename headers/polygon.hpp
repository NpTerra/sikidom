#pragma once

#include <iostream>
#include <vector>
#include "shape.hpp"

class Polygon : virtual public Shape {
    protected:
        std::vector<Point> vertices;
        Polygon(size_t vertices);
    public:
        Polygon(const std::vector<Point>& vertices);
        Polygon(const Polygon& poly);
        virtual ~Polygon() = default;

        virtual const Point& getAnchor() const;
        virtual const std::vector<Point>& getVertices() const;
        virtual size_t vCount() const;

        virtual double area() const;
        virtual double perimeter() const;

        virtual bool intersects(const Point& a, const Point& b) const;

        virtual bool contains(const Point& p) const;
        virtual bool contains(const Shape& s) const;
        
        virtual Polygon& operator=(const Polygon& poly);

        friend std::istream& operator>>(std::istream& is, Polygon& poly);
};
