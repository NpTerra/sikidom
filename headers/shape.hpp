#pragma once

#include <stddef.h>
#include "vector.hpp"
#include "point.hpp"

class Shape {
    protected:
        /**
         * Alakzat adatainak beolvasása a megadott bemenetről.
         * 
         * \param is A bemenet.
         */
        virtual void read(std::istream& is) = 0;

        /**
         * Alakzat adatainak kiírása a megadott kimenetre.
         * 
         * \param os A kimenet.
         */
        virtual void print(std::ostream& os) const = 0;
    public:
        virtual ~Shape() = default;

        /**
         * Megadja az alakzat horgonypontját.
         * 
         * \returns A horgonypont.
         */
        virtual const Point& getAnchor() const = 0;


        /**
         * Megadja az alakzat csúcsainak halmazát.
         * 
         * \returns A csúcsok halmaza.
         */
        virtual const Vector<Point>& getVertices() const = 0;


        /**
         * Megadja az alakzat csúcsainak számát.
         * 
         * \returns A csúcsok darabszáma.
         */
        virtual size_t vCount() const = 0;


        /**
         * Megadja az alakzat területét. (egység^2)
         * 
         * \returns Az alakzat területe.
         */
        virtual double area() const = 0;


        /**
         * Megadja egy alakzat kerületét. (egységhossz)
         * 
         * \returns Az alakzat kerülete.
         */
        virtual double perimeter() const = 0;


        /**
         * Megadja, hogy az alakzatot metszi-e egy megadott szakasz.
         * (van-e közösen lefedett terület)
         * 
         * \param a A szakasz első pontja.
         * \param b A szakasz második pontja.
         * 
         * \returns Igaz érték, ha a szakasz metszi az alakzatot.
         */
        virtual bool intersects(const Point& a, const Point& b) const = 0;


        /**
         * Megadja, hogy az alakzat területén található-e egy adott pont.
         * 
         * \param p A kérdéses pont.
         * 
         * \returns Igaz érték, ha a pont az alakzat területén található.
         */
        virtual bool contains(const Point& p) const = 0;


        /**
         * Megadja, hogy az alakzat teljes terjedelmében tartalmaz-e egy másik alakzatot.
         * 
         * \param s A másik alakzat.
         * 
         * \returns Igaz érték, ha a kérdéses pont teljes terjedelmében tartalmazva van.
         */
        virtual bool contains(const Shape& s) const = 0;


        /**
         * Adatok beolvasása megadott bemenetről egy alakzatba.
         * 
         * \param is A bemenet, amiről olvasni kell.
         * \param shape Az alakzat, amibe az adatokat be kell olvasni.
         * 
         * \returns A bemenet referenciája, hogy lehetővé tegye az operátor láncolását.
         */
        friend std::istream& operator>>(std::istream& is, Shape& shape);

        /**
         * Alakzat adatainak kiírása megadott kimenetre.
         * 
         * \param os A kimenet, amire az adatokat ki kell írni.
         * \param shape Az alakzat.
         * 
         * \returns A kimenet referenciája, hogy lehetővé tegye az operátor láncolását.
         */
        friend std::ostream& operator<<(std::ostream& os, Shape& shape);
};

std::istream& operator>>(std::istream& is, Shape& shape) {
    shape.read(is);

    return is;
}

std::ostream& operator<<(std::ostream& os, Shape& shape) {
    shape.print(os);

    return os;
}
