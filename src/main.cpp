#include <iostream>
#include "canvas.hpp"
#include "apputils.hpp"

int main() {
    
    /*
    ==================================
        MENÜVEZÉRELT PROGRAM HELYE
    ==================================
    */

    std::cout << "---<Main Start>---" << std::endl;
    
    Canvas canv;
    
    int n;
    do {
        printMenu();
        n = getNum(1, 8);
    } while(interact(canv, n));
    
    std::cout << "----<Main End>----" << std::endl;
}
