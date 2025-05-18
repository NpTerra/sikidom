#pragma once
#include <cstddef>
#include "canvas.hpp"

namespace utils {

    /**
     * Menü kiírása a standard kimenetre.
     */
    void printMenu();

    /**
     * Nemnegatív egész szám bekérése a standard bemenetről.
     * Megadott inkluzív határok között.
     * 
     * \param min Minimum határ.
     * \param max Maximum határ.
     * 
     * \returns A határokon belül az első megfelelő bemenet.
     */
    size_t getNum(size_t min, size_t max);

    /**
     * A felhasználó bemenetének feldolgozása a menüben.
     * 
     * \param canv A jelenleg érvényes Canvas.
     * \param n A felahsználó által megadott menüpont száma.
     * 
     * \returns Hogy a feldolgozás után folytatódjon-e még tovább a program.
     */
    bool interact(Canvas &canv, size_t n);
}