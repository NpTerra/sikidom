#pragma once

#include <cmath>
#include <iostream>

class Point {
    private:
        int cmp(const Point& p) const;
    public:
        double x, y;
        
        static const double MAXVAL;
        static const double MINVAL;

        Point(double x = 0.0, double y = 0.0);

        bool operator==(const Point& p) const;
        
        Point& operator=(const Point& p);

        Point operator+(const Point& p) const;
        Point operator-(const Point& p) const;

        /**
         * Distance
         */
        double operator|(const Point& p) const;
        /**
         * Dot Product
         */
        double operator*(const Point& p) const;
        /**
         * Cross Product
         */
        double operator%(const Point& p) const;
        
        friend std::istream& operator>>(std::istream& is, Point& p);

        #define Comp(x) bool operator x (Point q) const;
            Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
        #undef Comp
};