#pragma once

#include <cmath>
#include <iostream>

class Point {
    private:
        /**
         * A síkon elhelyezkedő pontok összehasonlítása. Első sorban X, majd Y koordináta alapján.
         * 
         * \param p A másik pont, amivel össze kell hasonlítani.
         * 
         * \returns math2d::cmp(x1, x2), ha x1 != x2, egyébként math2d::cmp(y1, y2) 
        */
        int cmp(const Point& p) const;

    public:
        double x; ///< X koordináta
        double y; ///< Y koordináta
        
        static const double MAXVAL; ///< X és Y értékek minimum határa
        static const double MINVAL; ///< X és Y értékek maximum határa

        Point(double x = 0.0, double y = 0.0);


        /**
         * Pont egyenlőségének vizsgálata egy másik ponttal.
         * 
         * \param p A másik pont.
         * 
         * \returns Igaz érték, ha a két pont X és Y koordinátái is megegyeznek.
         */
        bool operator==(const Point& p) const;
        

        /**
         * Jelenlegi pont felülírása egy másik megadott ponttal.
         * 
         * \param p A másik pont.
         * 
         * \returns A módosított pont.
         */
        Point& operator=(const Point& p);


        /**
         * Az adott pont összege egy másik ponttal.
         * 
         * \param p A másik pont.
         * 
         * \returns Egy új pont, ahol X és Y is a megfelelő koordináták összege.
         */
        Point operator+(const Point& p) const;

        /**
         * Az adott pont különbsége egy másik ponttal.
         * 
         * \param p A másik pont.
         * 
         * \returns Egy új pont, ahol X és Y is a megfelelő koordináták különbsége.
         */
        Point operator-(const Point& p) const;


        /**
         * Adott pont távolsága egy másik ponttól.
         * 
         * \param p A másik pont.
         * 
         * \returns A két pont távolsága.
         */
        double operator|(const Point& p) const;


        /**
         * Adott pont skaláris szorzata egy másik ponttal. (dot product)
         * 
         * \param p A másik pont.
         * 
         * \returns A két pont skaláris szorzata.
         */
        double operator*(const Point& p) const;

        
        /**
         * Adott pont vektoriális szorzata egy másik ponttal. (cross product)
         * 
         * \param p A másik pont.
         * 
         * \returns A két pont vektoriális szorzata.
         */
        double operator%(const Point& p) const;
        

        /**
         * Adatok beolvasása megadott bemenetről egy megadott pontba.
         * 
         * \param is A bemenet, amiről olvasni kell.
         * \param p A pont, amibe az adatokat be kell olvasni.
         * 
         * \returns A bemenet referenciája, hogy lehetővé tegye az operátor láncolását.
         */
        friend std::istream& operator>>(std::istream& is, Point& p);

        /**
         * Pont adatainak kiírása megadott kimenetre.
         * 
         * \param os A kimenet, amire az adatokat ki kell írni.
         * \param p A pont.
         * 
         * \returns A kimenet referenciája, hogy lehetővé tegye az operátor láncolását.
         */
        friend std::ostream& operator<<(std::ostream& os, Point& p);


        /**
         * @brief Pontokat összehasonlító operátorok definiálása makróval.
         *
         * A következő operátorok lesznek definiálva:
         * - operator>
         * - operator<
         * - operator==
         * - operator>=
         * - operator<=
         * - operator!=
         */
        #define Comp(x) bool operator x (Point q) const;
            Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
        #undef Comp
};