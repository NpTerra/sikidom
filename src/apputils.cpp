#include "apputils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "polygon.hpp"
#include "regulars.hpp"
#include "pointcloud.hpp"
#include "vector.hpp"

#include "memtrace.h"

/**
 * 
 */
void readFile(Canvas &canv) {
    std::cout << "Add meg a fájl elérési útját: ";
    std::cin.ignore(1, '\n');
    
    std::string path;
    std::getline(std::cin, path);

    std::ifstream is(path);
    if(!is.is_open()) {
        throw std::ios_base::failure("Nem sikerült megnyitni a megadott fájlt!");
    }

    size_t data;
    if(!(is >> data)) throw std::ios_base::failure("Nem sikerült beolvasni a beolvasandó adatok mennyiségét!");
    
    Canvas temp;

    for(size_t i = 0; i < data; i++) {
        Shape* shape;
        
        size_t t;
        if(!(is >> t)) throw std::ios_base::failure("Nem sikerült beolvasni a beolvasandó alakzat típusát!");

        switch(t) {
            case 0:
                shape = new Polygon();
                break;
            case 1:
                shape = new Regular();
                break;
            case 2:
                shape = new PointCloud();
                break;
            default:
                throw std::ios_base::failure("Nem létező alakzattípus lett beolvasva!");
        }

        if(!(is >> *shape)) throw std::ios_base::failure("Nem sikerült beolvasni az alakzat adatait!");
        temp.add(shape);
    }

    canv.add(temp);
}

namespace utils {
    void printMenu() {
        std::cout <<"\nVálassz az alábbi opciók közül:\n" <<
                    " 1 - Alakzatok beolvasása fájlból\n" <<
                    " 2 - Alakzat eltárolása\n" <<
                    " 3 - Alakzat törlése\n" <<
                    " 4 - Összes alakzat törlése\n" <<
                    " 5 - Alakzat adatainak kiírása\n" <<
                    " 6 - Összes alakzat kiírása\n" <<
                    " 7 - Alapterület ellenőrzés\n" <<
                    " 8 - Kilépés\n";
    }

    size_t getNum(size_t min, size_t max) {
        if(max < min)
            std::swap(min, max);

        size_t num = 0;
        do {
            std::cout << "Adj meg egy számot " << min << " és " << max << " között: ";
            std::cin >> num;
        } while((num < min || num > max) && std::cin);
        
        return num;
    }

    bool interact(Canvas &canv, size_t n) {
        size_t k;
        switch(n) {
            case 1:
                try {
                    readFile(canv);
                } catch(const std::ios_base::failure& ex) {
                    std::cerr << ex.what() << std::endl;
                }
                break;
            case 2:
                std::cout << "Típusok:\n" <<
                            " 0 - Sokszög\n" <<
                            " 1 - Szabályos alakzat\n" <<
                            " 2 - Pontfelhő\n";
                k = getNum(0, 2);
                Shape* shape;
                switch(k) {
                    case 0:
                        shape = new Polygon();
                        break;
                    case 1:
                        shape = new Regular();
                        break;
                    case 2:
                        shape = new PointCloud();
                        break;
                }
                if(!(std::cin >> *shape)) {
                    delete shape;
                    std::cerr << "Nem sikerült beolvasni az alakzat adatait!" << std::endl;
                }
                else canv.add(shape);

                break;
            case 3:
                if(canv.size() == 0) {
                    std::cout << "Nincs eltárolva egyetlen alakzat sem!" << std::endl;
                    break;
                }
                k = getNum(0, canv.size()-1);
                canv.remove(k);
                std::cout << "Az alakzat törölve lett a listából!";
                break;
            case 4:
                canv.clear();
                std::cout << "Az összes alakzat törölve lett a listából!";
                break;
            case 5:
                if(canv.size() == 0) {
                    std::cout << "Nincs eltárolva egyetlen alakzat sem!" << std::endl;
                    break;
                }
                k = getNum(0, canv.size()-1);
                canv.print(k, std::cout);
                break;
            case 6:
                if(canv.size() == 0) {
                    std::cout << "Nincs eltárolva egyetlen alakzat sem!" << std::endl;
                    break;
                }
                std::cout << "Eltárolt alakzatok:\n";
                canv.printAll(std::cout);
                break;
            case 7:
                if(canv.size() == 0) {
                    std::cout << "Nincs eltárolva egyetlen alakzat sem!" << std::endl;
                    break;
                }
                k = getNum(0, canv.size()-1);
                std::cout << "A kiválasztott alakzat" <<
                            (canv.isBaseShape(k) ? "" : " nem") <<
                            " alkalmas alapterüeltnek!" << std::endl;
                break;
            default:
                return false;
        }

        return true;
    }
}