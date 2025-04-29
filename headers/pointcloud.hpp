#pragma once

#include <iostream>
#include "vector.hpp"
#include "point.hpp"
#include "shape.hpp"
#include "polygon.hpp"

class PointCloud : private Polygon, virtual public Shape {
    private:
        Vector<Point> points;   ///< a Pontfelhő pontjai.

        /**
         * A konvex burok kiszámítása a pontfelhő pontjaiból.
         */
        void setHull();
    protected:
        /**
         * Adatok beolvasása megadott bemenetről egy megadott pontfelhőbe.
         * 
         * \param is A bemenet, amiről olvasni kell.
         */
        virtual void read(std::istream& is) override;
        
        /**
         * Pontfelhő adatainak kiírása megadott kimenetre.
         * 
         * \param os A kimenet, amire az adatokat ki kell írni.
         */
        virtual void print(std::ostream& os) const override;
    public:
        PointCloud(size_t points = 0);
        PointCloud(const Vector<Point>& points);
        PointCloud(const PointCloud& pc);
        virtual ~PointCloud() = default;

        /**
         * \copydoc Shape::getAnchor()
         * 
         * \remarks
         * Pontfelhő esetén a konvex burok első eleme.
         */
        using Polygon::getAnchor;

        /**
         * Megadja a pontfelhő konvex burkát alkotó pontok halmazát.
         * 
         * \returns A konvex burok pontjainak halmaza.
         */
        using Polygon::getVertices;


        /**
         * Megadja a pontfelhő konvex burkát alkotó pontok számát
         * 
         * \returns A konvex burok pontjainak száma.
         */
        using Polygon::vCount;

        /**
         * Megadja a pontfelhő pontjainak halmazát.
         * 
         * \returns A pontok halmaza.
         */
        const Vector<Point>& getPoints() const;
        

        /**
         * Megadja a pontfelhő konvex burkának területét. (egység^2)
         * 
         * \returns A konvex burok területe.
         */
        using Polygon::area;


        /**
         * Megadja a pontfelhő konvex burkának kerületét. (egységhossz)
         * 
         * \returns A konvex burok kerülete.
         */
        using Polygon::perimeter;

        using Polygon::intersects;

        using Polygon::contains;

        /**
         * Pontfelhő felülírása egy másikkal.
         * 
         * \param pc A másik pontfelhő.
         * 
         * \returns A módosított pontfelhő.
         */
        PointCloud& operator=(const PointCloud& pc);
};