#pragma once

#include <iostream>
#include "point.hpp"
#include "shape.hpp"
#include "polygon.hpp"

class Regular : private Polygon, virtual public Shape {
    private:
        Point center;               ///< Szabályos alakzat középpontja.
        double r;                   ///< A "húrsokszög" körének sugara. (az osztály tárolhat sima kört is)
        double phi;                 ///< Kezdeti elforgatás fokban számolva.
        void calculateVertices();   ///< Szabályos alakzat csúcsainak kiszámítása a középponthoz képest.
    public:
        Regular(size_t vertices = 0, double radius = 1.0, Point center = {0, 0}, double phi = 0);
        Regular(const Regular& reg);
        virtual ~Regular() = default;

        /**
         * \copydoc Shape::getAnchor()
         * 
         * \remarks
         * Szabályos alakzat esetén az alakzat középpontja.
         */
        const Point& getAnchor() const override;
        using Polygon::getVertices;
        using Polygon::vCount;
        
        double area() const override;
        using Polygon::perimeter;

        virtual bool intersects(const Point& a, const Point& b) const override;

        virtual bool contains(const Point& p) const override;
        virtual bool contains(const Shape& s) const override;

        Regular& operator=(const Regular& reg);

        friend std::istream& operator>>(std::istream& is, Regular& reg);
};