#pragma once

#include <iostream>
#include "vector.hpp"
#include "shape.hpp"

class Polygon : virtual public Shape {
    protected:
        Vector<Point> vertices;     ///< A sokszög csúcsai.
        
        /**
         * Adatok beolvasása megadott bemenetről egy megadott sokszögbe.
         * 
         * \param is A bemenet, amiről olvasni kell.
         */
        virtual void read(std::istream& is) override;
        
        /**
         * Sokszög adatainak kiírása megadott kimenetre.
         * 
         * \param os A kimenet, amire az adatokat ki kell írni.
         */
        virtual void print(std::ostream& os) const override;
    public:
        Polygon(size_t vertices = 0);
        Polygon(const Vector<Point>& vertices);
        Polygon(const Polygon& poly);
        virtual ~Polygon() {};

        virtual Shape* clone() const override;

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
        Polygon& operator=(const Polygon& poly);
};
