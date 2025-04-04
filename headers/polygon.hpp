#pragma once

#include <iostream>
#include <vector>
#include "shape.hpp"

class Polygon : virtual public Shape {
    protected:
        std::vector<Point> vertices;
    public:
        Polygon(size_t vertices);
        Polygon(const std::vector<Point>& vertices);
        Polygon(const Polygon& poly);
        virtual ~Polygon() = default;

        virtual inline const Point& getAnchor() const { return vertices[0]; }
         inline const std::vector<Point>& getVertices() const { return vertices; };
        inline size_t vCount() const { return vertices.size(); }

        virtual double area() const;
        virtual double perimeter() const;

        virtual bool intersects(const Point& a, const Point& b) const;

        virtual bool contains(const Point& p) const;
        virtual bool contains(const Shape& s) const;
        
        virtual Polygon& operator=(const Polygon& poly);

        friend std::istream& operator>>(std::istream& is, Polygon& poly);
};
