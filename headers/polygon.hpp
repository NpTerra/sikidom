#pragma once

#include <iostream>
#include "vector.hpp"
#include "shape.hpp"

class Polygon : virtual public Shape {
    protected:
        Vector<Point> vertices;
        Polygon(size_t vertices);
    public:
        Polygon(const Vector<Point>& vertices);
        Polygon(const Polygon& poly);
        virtual ~Polygon() = default;

        virtual const Point& getAnchor() const override;
        virtual const Vector<Point>& getVertices() const override;
        virtual size_t vCount() const override;

        virtual double area() const override;
        virtual double perimeter() const override;

        virtual bool intersects(const Point& a, const Point& b) const override;

        virtual bool contains(const Point& p) const override;
        virtual bool contains(const Shape& s) const override;
        
        virtual Polygon& operator=(const Polygon& poly);

        friend std::istream& operator>>(std::istream& is, Polygon& poly);
};
