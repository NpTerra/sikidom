#include <iostream>
#include "canvas.hpp"
#include "apputils.hpp"
#include "gtest_lite.h"

#if defined(CPORTA) && !defined(TESTING)
#define TESTING
#endif

#ifdef TESTING
#include "tests.hpp"
#endif

#include "memtrace.h"

int main() {

    /*
    ==================================
         TESZTELÉS, HA VAN CPORTA
    ==================================
    */

    #ifdef TESTING
    runTests();
    #endif

    /*
    ==================================
        MENÜVEZÉRELT PROGRAM HELYE
    ==================================
    */

    std::cout << "---<Main Start>---" << std::endl;
    
    Canvas canv;
    
    size_t n;
    do {
        utils::printMenu();
        n = utils::getNum(1, 8);
    } while(utils::interact(canv, n));
    
    std::cout << "\n----<Main End>----" << std::endl;
}
