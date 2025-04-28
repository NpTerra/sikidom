#pragma once

#include <iostream>
#include "vector.hpp"
#include "shape.hpp"

class Polygon : virtual public Shape {
    protected:
        Vector<Point> vertices;     ///< A sokszög csúcsai.
        Polygon(size_t vertices);
    public:
        Polygon(const Vector<Point>& vertices);
        Polygon(const Polygon& poly);
        virtual ~Polygon() = default;

        /**
         * \copydoc Shape::getAnchor()
         * 
         * \remarks
         * Sokszög esetén a ponthalmaz első eleme.
         */
        virtual const Point& getAnchor() const override;
        virtual const Vector<Point>& getVertices() const override;
        virtual size_t vCount() const override;

        virtual double area() const override;
        virtual double perimeter() const override;

        virtual bool intersects(const Point& a, const Point& b) const override;

        virtual bool contains(const Point& p) const override;
        virtual bool contains(const Shape& s) const override;
        

        /**
         * Sokszög felülírása egy másikkal.
         * 
         * \param poly A másik sokszög.
         * 
         * \returns A módosított sokszög.
         */
        virtual Polygon& operator=(const Polygon& poly);

        /**
         * Adatok beolvasása megadott bemenetről egy megadott sokszögbe.
         * 
         * \param is A bemenet, amiről olvasni kell.
         * \param poly A sokszög, amibe az adatokat be kell olvasni.
         * 
         * \returns A bemenet referenciája, hogy lehetővé tegye az operátor láncolását.
         */
        friend std::istream& operator>>(std::istream& is, Polygon& poly);
};
