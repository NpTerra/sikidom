#pragma once
#include <cstddef>
#include "canvas.hpp"

namespace utils {
    void printMenu();

    size_t getNum(size_t min, size_t max);

    bool interact(Canvas &canv, size_t n);
}