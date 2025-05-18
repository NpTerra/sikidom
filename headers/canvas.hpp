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
         * Megadja az eltárolt alakzatok számát.
         * 
         * \returns Az eltárolt elemek száma.
         */
        size_t size() const;

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
         * Másik Canvasban lévő alakzatok másolatának hozzáadása a mostanihoz.
         * 
         * \param canv A másik Canvas.
         */
        void add(const Canvas& canv);

        /**
         * Alakzat adatainak kiírása.
         * 
         * \param index Az alakzat indexe.
         * \param os A kimenet, amire írni kell.
         * 
         * \throws std::out_of_range Ha az index kilóg az eltárolt alakzatok határán.
         */
        void print(size_t index, std::ostream& os) const;

        /**
         * Összes alakzat adatainak kilistázása.
         * 
         * \param os A kimenet, amire írni kell.
         */
        void printAll(std::ostream& os) const;

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
        bool isBaseShape(size_t index) const;
};