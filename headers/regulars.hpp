#pragma once

#include <cmath>

class Regular : private Polygon {
    private:
        Point center;
        double r, phi;
        void calculateVertices();
    public:
        Regular(size_t vertices = 0, double radius = 1.0, Point center = {0, 0}, double phi = 0);
        virtual ~Regular() = default;

        virtual inline const Point& getAnchor() const { return center; }
        using Polygon::getVertices;
        using Polygon::vCount;
        
        double area() const;
        using Polygon::perimeter;

        virtual bool intersects(const Point& a, const Point& b) const;

        virtual bool contains(const Point& p) const;
        virtual bool contains(const Shape& s) const;

        Regular& operator=(const Regular& reg);

        friend std::istream& operator>>(std::istream& is, Regular& reg);
};