#pragma once

#include "point.hpp"

namespace math2d {
    
    enum DIRECTION {
        CENTER = 0,
        LEFT = 1,
        RIGHT = -1,
        BACK = -2,
        FRONT = 2
    };
    
    /**
     * Összehasonlít két azonos típusú értéket.
     * \param x Az első érték.
     * \param y A második érték.
     * \returns Ha azonosak: 0, ha x<y: -1, ha x>y: 1
     */
    template<typename T>
    int cmp(T x, T y) {
        if (x == y) return 0;
        if (x < y) return -1;
        return 1;
    }


    /**
     * @brief Három pont 2D-s irányítottságát számítja ki.
     * 
     * Kiszámítja a (b-a) és (c-a) vektorok által meghatározott parallelogramma előjeles területét.
     * 
     * @param a Az első pont
     * @param b A második pont
     * @param c A harmadik pont
     * 
     * @returns Pozitív érték, ha az a,b,c pontok az óramutató járásával ellentétes háromszöget alkotnak.
     *          Negatív érték, ha a pontok az óramutató járásával megegyező háromszöget alkotnak.
     *          Nulla, ha a pontok kollineárisak (egy egyenesen helyezkednek el).
     * 
     * \remarks
     * A visszatérési érték abszolút értéke az abc háromszög területének kétszeresét jelenti.
     */
    inline double orient(const Point& a, const Point& b, const Point& c)
    {
        return (b-a)%(c-a);
    }


    /**
     * Leegyszerűsíti a math2d::orient() függvényt.
     * Visszatérésként már a math2d::DIRECTION-ben meghatározott irányokat használja.
     * 
     * @param a Az első pont
     * @param b A második pont
     * @param c A harmadik pont
     * 
     * \returns LEFT, ha az a,b,c pontok az óramutató járásával ellentétes háromszöget alkotnak.
     *          RIGHT, ha a pontok az óramutató járásával megegyező háromszöget alkotnak.
     *          CENTER, ha a pontok kollineárisak (egy egyenesen helyezkednek el).
     */
    inline DIRECTION leaning(const Point& a, const Point& b, const Point& c)
    {
        double o = orient(a, b, c);
        if(o > 0) return LEFT;
        if(o < 0) return RIGHT;
        
        return CENTER;
    }


    /**
     * Megadja, hogy három pont kollineáris-e egymással (egy egyenesen helyezkednek el).
     * 
     * @param a Az első pont
     * @param b A második pont
     * @param c A harmadik pont
     * 
     * \returns Igaz érték, ha kollineárisak.
     */
    inline bool collinear(const Point& a, const Point& b, const Point& c)
    {
        return orient(a, b, c) == 0;
    }


    /**
     * Megadja, hogy egy pont rajta van-e egy adott szakaszon.
     * 
     * \param p A kérdéses pont.
     * \param a A szakasz első pontja.
     * \param b A szakasz második pontja.
     * 
     * \returns Igaz érték, ha a pont rajta van a szakaszon.
     */
    bool isPointOnSegment(const Point& p, const Point& a, const Point& b);


    /**
     * Megadja, hogy két szakasz metszi-e egymást.
     * 
     * \param a Az első szakasz első pontja.
     * \param b Az első szakasz második pontja.
     * \param c Az második szakasz első pontja.
     * \param d Az második szakasz második pontja.
     */
    bool doIntersect(const Point& a, const Point& b,
                    const Point& c, const Point& d);
    
    /**
     * Megadja, hogy egy kör és egy szakasz metszi-e egymást.
     * 
     * \param s1 A szakasz első pontja.
     * \param s2 A szakasz második pontja.
     * \param center A kör középpontja.
     * \param r A kör sugara.
     * 
     * \returns Igaz érték, ha a kör és a szakasz metszi egymást.
     */
    bool doLineSegmentAndCircleIntersect(const Point& s1, const Point& s2,
                                        const Point& center, double r);
}