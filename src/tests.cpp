#include "tests.hpp"

#include <iostream>
#include "gtest_lite.h"

#include "canvas.hpp"
#include "shape.hpp"
#include "point.hpp"
#include "polygon.hpp"
#include "regulars.hpp"
#include "pointcloud.hpp"

#include <string>
#include <sstream>
using std::string;
using std::istringstream;
using std::ostringstream;

#include "memtrace.h"

double dec2(double d) {
    return round(d*100.0)/100;
}

void runTests() {
    TEST(Adatok, Pont) {
        istringstream a(string("10 20 20 10"));
        ostringstream b;
        Point p1, p2;
        a >> p1 >> p2;
        
        Point p3 = p1+p2;
        b << p3;
        EXPECT_STREQ("30 30", b.str().c_str());
    } END;

    TEST(Adatok, Heterogen) {
        istringstream a(string("3 0 0 10 10 10 0   4 0 0 50 45"));
        istringstream b(string("5 0 0 3 0 3 3 0 3 1.5 1.5"));

        Shape* poly = new Polygon();
        Regular* reg = new Regular();
        PointCloud* cl = new PointCloud();
        a >> *poly >> *reg;
        b >> *cl;
        
        Canvas canv;
        canv.add(poly);
        canv.add(reg);
        canv.add(cl);

        EXPECT_TRUE(canv.isBaseShape(1));
    } END;


    string circles ("0 0 0 10 0 "
                     "0 0 0 20 0 "
                     "0 0 0 30 0 "
                     "0 5 5 10 0");
    string reg = "4 0 0 20 45";
    string poly =  "8 0 25 -10 10 -25 0 -10 -10 0 -25 10 -10 25 0 10 10 ";
    string cloud = "6 25 25 -25 25 2 2 25 -25 -4 7 -25 -25 "
                    "10 25 25 0 50 -25 25 2 2 50 0 25 -25 -4 7 -70 0 -25 -25 0 -40";

    Shape* c1 = new Regular();
    Shape* c2 = new Regular();
    Shape* c3 = new Regular();
    Shape* c4 = new Regular();
    istringstream(circles) >> *c1 >> *c2 >> *c3 >> *c4;

    Shape* r1 = new Regular();
    istringstream(reg) >> *r1;

    Shape* p1 = new Polygon();
    istringstream(poly) >> *p1;
    
    Shape* cl = new PointCloud();
    PointCloud* cl2 = new PointCloud();
    istringstream(cloud) >> *cl >> *cl2;

    std::cout << *cl << "\n";
    
    
    Canvas canv;
    canv.add(c1);
    canv.add(c2);
    canv.add(c3);
    canv.add(c4);
    canv.add(r1);
    canv.add(cl2);
    canv.add(p1);
    canv.add(cl);

    TEST(Terulet, Osszes) {
        std::cout << dec2(c4->area()) << " " << dec2(r1->area()) << " " << dec2(p1->area()) << " " << dec2(cl->area()) << "\n";
        EXPECT_TRUE(gtest_lite::almostEQ(dec2(c4->area()), 314.16));
        EXPECT_TRUE(gtest_lite::almostEQ(dec2(r1->area()), 800.0));
        EXPECT_TRUE(gtest_lite::almostEQ(dec2(p1->area()), 1000.0));
        EXPECT_TRUE(gtest_lite::almostEQ(dec2(cl->area()), 2500.0));
    } END;
    
    TEST(Tartalmaz, Kor_Kor) {
        EXPECT_TRUE(c3->contains(*c2));
        EXPECT_FALSE(c2->contains(*c3));
        EXPECT_FALSE(c1->contains(*c4));
    } END;

    TEST(Tartalmaz, Kor_Poly) {
        EXPECT_FALSE(c1->contains(*p1));
        EXPECT_FALSE(c2->contains(*p1));
        EXPECT_TRUE(c3->contains(*p1));
        EXPECT_FALSE(c4->contains(*p1));
    } END;

    TEST(Tartalmaz, Poly_Kor) {
        EXPECT_TRUE(p1->contains(*c1));
        EXPECT_FALSE(p1->contains(*c2));
        EXPECT_FALSE(p1->contains(*c3));
        EXPECT_FALSE(p1->contains(*c4));
    } END;

    canv.remove(3);
    TEST(Alapterulet, Osszes) {
        for(size_t i = 0; i < canv.size(); i++)
            if(i == 4) EXPECT_TRUE(canv.isBaseShape(i));
            else       EXPECT_FALSE(canv.isBaseShape(i));
    } END;
}