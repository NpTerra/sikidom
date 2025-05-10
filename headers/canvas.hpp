#pragma once

#include <iostream>
#include "vector.hpp"
#include "shape.hpp"

class Canvas {
    private:
        Vector<Shape*> shapes; ///< Az alakzatok listája. (heterogén kollekció)
    public:
        Canvas();
        ~Canvas();

        /**
         * Alakzat törlése a listából.
         * 
         * \param index A törlendő alakzat indexe.
         * 
         * \throws std::out_of_range Ha az index kilóg az eltárolt alakzatok határán.
         */
        void remove(size_t index);

        /**
         * Törli az összes alakzatot.
         */
        void clear();

        /**
         * Alakzat hozzáadása alistához.
         * 
         * \param s A hozzáadandó alakzat pointere.
         */
        void add(Shape* s);

        /**
         * Alakzat adatainak kiírása.
         * 
         * \param index Az alakzat indexe.
         * \param os A kimenet, amire írni kell.
         * 
         * \throws std::out_of_range Ha az index kilóg az eltárolt alakzatok határán.
         */
        void print(size_t index, std::ostream& os);

        /**
         * Összes alakzat adatainak kilistázása.
         * 
         * \param os A kimenet, amire írni kell.
         */
        void printAll(std::ostream& os);

        /**
         * Meghatározza, hogy egy alakzat alkalmas-e alapterületnek.
         * (minden másik eltárolt alakzatot teljes terjedelmükben tartalmazza)
         * 
         * \param index Az alakzat indexe.
         * 
         * \returns Igaz érték, ha alkalmas alapterületnek.
         * 
         * \throws std::out_of_range Ha az index kilóg az eltárolt alakzatok határán.
         */
        bool isBaseShape(size_t index);

        /**
         * Alakzatok beolvasása bemenetről.
         * Elsődlegesen fájlból való beolvasás céljából.
         * 
         * \param is A bemenet.
         * \param c Az alakzatok tárolója.
         * 
         * \returns A bemenet referenciája, hogy lehetővé tegye az operátor láncolását.
         */
        friend std::istream& operator<<(std::istream& is, Canvas& c);
};